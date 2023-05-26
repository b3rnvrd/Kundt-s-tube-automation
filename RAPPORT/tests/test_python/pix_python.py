mots ='FORGES COFFRET CLAPET NOIRCIR FLORES ASTRILD CREPES POULAIN HANSES POIGNET'
a = 0
b = len(mots)
titi=''
for i in range(0, int(len(mots)/2)):
    if (mots[i]==' '):
        titi = titi + mots[abs(a-b)]
    a = a + 2
    b = b - 1
print(titi)