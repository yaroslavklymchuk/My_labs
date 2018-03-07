import pandas as pd
import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import KFold, GridSearchCV, cross_val_score as score
from sklearn.feature_extraction.text import TfidfVectorizer, CountVectorizer
from sklearn.pipeline import make_pipeline
import io
from collections import Counter
from scipy.sparse import hstack

data_train = pd.read_csv('E:\\PycharmProjects\\Machine_L\\Data_Science_Club\\second_\\train.csv')
data_test = pd.read_csv('E:\\PycharmProjects\\Machine_L\\Data_Science_Club\\second_\\test.csv')
class_names = ['toxic', 'severe_toxic', 'obscene', 'threat', 'insult', 'identity_hate']

all_text = pd.concat([data_train['comment_text'], data_test['comment_text']])
vectorizer_count = CountVectorizer(min_df = 5)
vectorizer_tf = TfidfVectorizer(min_df = 5)
vectorizer_count.fit(all_text)
vectorizer_tf.fit(all_text)

#1-й способ
top_word = vectorizer_tf.get_feature_names()[np.argsort(vectorizer_tf.idf_)[0]]

# 2-й способ
text = vectorizer_count.fit_transform(all_text)
counts = text.sum(axis=0).A1
vocab = vectorizer_count.get_feature_names()
freq_distribution = Counter(dict(zip(vocab, counts)))
top_word_ = freq_distribution.most_common(1)[0][0]

f = io.open('Top word.txt', 'w', encoding = 'utf-8')
f.write(top_word_)
f.close()

#needs too much time
'''
pipe = make_pipeline(LogisticRegression(), TfidfVectorizer(min_df = 5))
grid = {'LogisticRegression__C': np.power(10.0, np.arange(-5, 5)), 'LogisticRegression__solver': ['newthon-cg', 'lbfgs', 'liblinear', 'sag', 'saga'],
        'LogisticRegression__penalty': ['l1', 'l2'], 'TfidfVectorizer__max_df': [30000, 40000, 50000],
        'TfidfVectorizer__ngram_range': [(1,1), (1,2), (1,3)]}
scores_ = []
best_params = []
estimators = []
vectorizers = []
for cl_name in class_names:
    y_train = data_train[cl_name]
    X_train = data_train['comment_text']
    gs = GridSearchCV(pipe, grid, n_jobs = -1, scoring = 'roc_auc', cv=KFold(n_splits = 5, shuffle = True, random_state = 241))
    gs.fit(X_train, y_train)
    scores_.append(gs.best_score_)
    best_params.append(gs.best_params_)
    estimators.append(gs.best_estimator_.named_steps['logisticregression'])
    vectorizers.append(gs.best_estimator_.named_steps['tfidfvectorizer'])
    for scores in gs.grid_scores_:
        print(scores.mean_validation_score)
        print(scores.parameters)


submission = pd.DataFrame.from_dict({'id': data_test['id']})
index = 0
for cl_name, vect in zip(class_names, vectorizers):
    clf = estimators[index]
    vectorizer = vect
    y_train = data_train[cl_name]
    X_train = vect.fit_transform(data_train['comment_text'])
    X_test = vect.fit_transform(data_test['comment_text'])
    clf.fit(X_train, y_train)
    submission[cl_name] = clf.predict_proba(X_test)[:, 1]

submission.to_csv('submission.csv', index=False)
'''

vect_tf = TfidfVectorizer(min_df = 5, max_df = 40000)
train_text_features_tf = vect_tf.transform(data_train['comment_text'])
test_text_features_tf = vect_tf.transform(data_test['comment_text'])

grid = {'C': np.power(10.0, np.arange(-5, 5))}
scores_vectorizer_tf = []
best_params_vectorizer_tf = []
for cl_name in class_names:
    y_train = data_train[cl_name]
    gs = GridSearchCV(LogisticRegression(penalty = 'l2', solver='sag'), grid, n_jobs = -1, scoring = 'roc_auc', cv=KFold(n_splits = 5, shuffle = True, random_state = 241))
    gs.fit(train_text_features_tf, y_train)
    scores_vectorizer_tf.append(gs.best_score_)
    best_params_vectorizer_tf.append(gs.best_params_)
    for scores in gs.grid_scores_:
        print(scores.mean_validation_score)
        print(scores.parameters)

mean_score = np.mean(scores_vectorizer_tf)# среднее значение

submission = pd.DataFrame.from_dict({'id': data_test['id']})
for cl_name, C_par in zip(class_names, best_params_vectorizer_tf):
    clf = LogisticRegression(C = C_par, solver='sag')
    y_train = data_train[cl_name]
    clf.fit(train_text_features_tf, y_train)
    submission[cl_name] = clf.predict_proba(test_text_features_tf)[:, 1]
submission.to_csv('submission_first.csv', index=False)


'''
stemmer = PorterStemmer()
def stem_tokens(tokens, stemmer):
    stemmed = []
    for item in tokens:
        stemmed.append(stemmer.stem(item))
    return stemmed

def tokenize(text):
    tokens = nltk.word_tokenize(text)
    stems = stem_tokens(tokens, stemmer)
    return stems
'''