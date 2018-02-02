# TP n°1: Optimisation

##  Exercice 1 *(Méthodes à pas constant)*

### 1) Gradiant à pas constant

Ecrire la fonction `[x, Jx, GJx, nit] = GCST(J, GJ, x0, pas ,epsil, nitmax)` qui calcule le minimum de la fonction 'J' dont le gradient est donné par la fonction `GJ`, par la méthode du gradient à pas constant;  à partir de l'initialisation `xO`.

### 2) Application à f(x) pour n=1 et n=2.

Le script `script1_1.m` effecutue l'application de la méthode du gradiant à pas constant à la fonction $f()$ pour $n=1$.

Nous obtenons les courbes suivantes: 

- Tout d'abord la courbe représentant le nombre d'itérations effectuées avant que la fonction `GCST()` ne retourne.

![Exo1-2-fn1](Images/Exo1-2-fn1.png)

Nous distinguons trois parties dans ce graphe:

1. Pour `pas`$\in [0.1, 1[$ la méthode converge rapidement
2. Pour `pas` $= 1$, la fonction `GCST()`retourne au bout du maximum d'itération permises sans avoir convergé.
3. Pour `pas` $> 1​$, la méthode parait converger. Cependant un examen plus attentif montre que les valeurs retournées pour `x`  et `Jx` sont en fait égales à `NaN`. La méthode de gradient à pas constant a dans ce cas  retourné sans avoir convergé. Les valeurs calculées ont divergé jusqu'à entrer dans des valeurs non supportées par le système.

Le script `script1_2.m` effectue le même calcul sur la fonction $f()$ pour $n=2$.

Nous obtenons le graphe suivant: 

![Exo1-2-fn2](Images/Exo1-2-fn2.png)

Nous constatons que la courbe est identique pour $n=1$ et $n=2$.

<!--Ajouter bafouille de pourquoi c'est le cas - voir de TD.-->

### 3) Gradient conjugué à pas constant

#### Pour $f$ avec $n=1$:

Le script `script1_3.m` applique la méthode de gradient conjugué de Dai-Yuan à pas constant sur la fonction $f$ pour $n=1$. Le résultat est le suivant:

![Exo1-3-fn1](Images/Exo1-3-fn1.png)



Pour $f$ avec $n=2$:

Le script `script1_4.m` applique la même méthode de gradient conjugé à pas constant sur la fonction $f$ pour $n = 2$. Le résultat est le suivant:

![Exo1-3-fn2](Images/Exo1-3-fn2.png)



### 4) Méthodes de gradients avec g(x)

![Exo1-3-fn2](Images/Exo1-3-fn2.png)