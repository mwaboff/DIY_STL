import urllib2, re

res=urllib2.urlopen("http://randomtextgenerator.com/")
html=res.read()
rawwords = re.findall('textarea(.*?)/textarea', html.replace('\n',''))[0]
words=re.findall('([a-zA-Z]{1,20})', rawwords)
print words
histo={}
f=file('sets','w')
g=file('results','w')
for word in words:
    f.write(word+'\n')
    if word in histo:
        histo[word]+=1
    else:
        histo[word]=1
for key in histo:
    g.write(key+' '+str(histo[key])+'\n')
f.close()
g.close()
