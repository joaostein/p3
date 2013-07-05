# 1º Bimestre

## Listas Lineares

As listas são compostas normalmente por um array e uma váriavel para contar a quantidade de elementos já inseridos. As ações que utilizamos em uma lista são:

- Criar uma nova lista (create)
- Adicionar um novo elemento (add)
- Pesquisar um novo elemento (search)
- Remover um elemento já existente (delete)
- Atualizar um elemento dado uma valor a ser alterado (update)

### Estrutura de uma lista

    typedef struct Lista {
        int quantElementos;
        int dados[N];
    } Lista;

### Create

    Lista *create () {
        Lista *l = malloc(sizeof(Lista));
        l->quantElementos = 0;
        return l;
    }

### Add

    void add (Lista *l, int el) {
        if (l->quantElementos < N - 1) {
            l->dados[l->quantElementos] = el;
            l->quantElementos++;
        } else {
            printf("Lista está cheia.\n");
        }
    }

### readAll

    void readAll (Lista *l) {
        int i;
        for (i = 0; i < l->quantElementos; i++) {
            printf("Dados[%d] = %d\n", i, l->dados[i]);
        }
    }

### Delete

    void delete (Lista *l, int el) {
        int i, j;

        for (i = 0; i < l->quantElementos; i++) {
            if (l->dados[i] == el) {
                for (j = i; j < l->quantElementos; j++) {
                    l->dados[j] = l->dados[j + 1];
                }
                l->quantElementos--;
            }
        }
    }

### Update

    void update (Lista *l, int key, int el) {
        int i;
        for (i = 0; i < l->quantElementos; i++) {
            if (l->dados[i] == key) {
                l->dados[i] = el;
            }
        }
    }

### Search

    int search (Lista *l, int el) {
        int i;
        for (i = 0; i < l->quantElementos; i++) {
            if (l->dados[i] == el) {
                printf("Elemento %d encontrado. Na posicao dados[%d].\n", l->dados[i], i);
                return l->dados[i];
            }
        }
        printf("Elemento não encontrado.\n");
    }



## Ordenação

### Bubblesort

Os elementos maiores são jogados pro final do vetor. De forma que você tem um laço de repetição que começa do início e vai até o fim, comparando elemento a elemento em cada passo do laço e fazendo a troca de posições caso o elemento anterior seja menor.

Opção 1: Recebe uma estrutura completa do tipo Lista. A mesma contem a quantidade de elementos.

    void bubblesort (Lista *l) {
        int i, j, aux;

        for (i = l->quantElementos - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (l->dados[j] > l->dados[j + 1]) {
                    aux = l->dados[j + 1];
                    l->dados[j + 1] = l->dados[j];
                    l->dados[j] = aux;
                }
            }
        }
    }

Opção 2: Passa o vetor e o tamanho dele através dos parametros da função.

    void bubblesort (int *elements, int size) {
        int i, j, tmp;
        for (i = size - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (elements[j] > elements[j + 1]) {
                    tmp = elements[j + 1];
                    elements[j + 1] = elements[j];
                    elements[j] = tmp;
                }
            }
        }
    }


### Insertionsort

Se assemelha com a organização das cartas de um jogo de baralho na mão. Você precisará de dois laços. Um principal e outro interno. O principal (i) será sempre uma unidade a frente do secundário (j). Portanto as comparações vão ser sempre feitas da forma "i < j ?". Se sim, haverá a troca de posição do elemento de (i) com o de (j). O laço secundário assegurará que cada vez que o (i) for avançando no array, ele compare a posição atual com todas as outras anteriores até o iníco do vetor. Dessa forma o laço principal (i) será sempre incrementado e o secundário (j) decrementado

Opção 1: Recebe uma estrutura completa do tipo Lista. A mesma contem a quantidade de elementos.

    void insertionSort (Lista *l) {
        int i, j, aux;

        for (i = 1; i < l->quantElementos; i++) {
            aux = l->dados[i];
            for (j = i - 1; j >= 0 && aux < l->dados[j]; j--) {
                l->dados[j + 1] = l->dados[j];
            }
            l->dados[j + 1] = aux;
        }
    }

Opção 2: Passa o vetor e o tamanho dele através dos parametros da função.
    
    void insertionSort (int *elements, int size) {
        int i, j, currentPosition;

        for (i = 1; i <= size; i++) {
            currentPosition = elements[i];
            for (j = i - 1; j >= 0 && elements[j] > currentPosition; j--) {
                elements[j + 1] = elements[j];
            }
            elements[j + 1] = currentPosition;
        }
    }


### Selectionsort

Precisa de dois laços, um externo (i) e outro interno (j) e uma variavel que armazenará a posição do menor elemento a cada volta do laço externo. Assim, a medida que o (i) vai indo em direção ao final do vetor, em cada passo, o laço interno garante que irá percorrer todos os elementos e verificar se existe algum elemento menor que o elemento na posição (i). Se for menor, ele irá fazer a troca do elemento na posição menor com o elemento na posiçao (i).

Opção 1: Recebe uma estrutura completa do tipo Lista. A mesma contem a quantidade de elementos.

    void selectionSort (Lista *l) {
        int i, j, menorElemento, aux;

        for (i = 0; i < l->quantElementos - 1; i++) {
            menorElemento = i;
            for (j = i + 1; j < l->quantElementos; j++) {
                if (l->dados[j] < l->dados[menorElemento]) {
                    menorElemento = j;
                }
            }
            aux = l->dados[i];
            l->dados[i] = l->dados[menorElemento];
            l->dados[menorElemento] = aux;
        }
    }

Opção 2: Passa o vetor e o tamanho dele através dos parametros da função.

    void selectionsort(int *elements, int size) {
        int i, j, pos, tmp;

        for(i = 0; i <= size - 2; i++) {
            pos = i;

            for(j = i + 1; j <= size - 1; j++) {
                if(elements[j] < elements[pos]) {
                    pos = j;
                }
            }

            tmp = elements[i];
            elements[i] = elements[pos];
            elements[pos] = tmp;
        }
    }

### Merge

Merge serve para concatenar dois vetores (ordenados) em um único, mantendo a ordem no vetor final. Consiste em ir percorrendo os dois vetores e ir fazendo comparações. Se inicia comparando o primeiro elemento do primeiro vetor com o primeiro elemento do segundo vetor. Se o elemento do primeiro vetor for menor ou igual ao elemento do segundo vetor, o elemento do primeiro vetor é colocado no novo vetor e é incrementada uma unidade na posição do primeiro laço que percorre o primeiro vetor. A comparação é feita novamente e assim sucessivamente. Caso o elemento no primeiro vetor for maior que o elemento no segundo vetor, o elemento do segundo vetor é passado para o novo vetor e é incrementado uma unidade na posição do segundo vetor. Isso é feito até ser preenchida todas as posiçoes.

    #define N 8

    int merge (int p, int q, int r, int v[]) {

        int i, j, k, w[r - p];
        i = p;
        j = q;
        k = 0;

        while (i < q && j < r) {
            if (v[i] <= v[j]) {
                w[k++] = v[i++];
            } else {
                w[k++] = v[j++];
            }
        }

        while (i < q) {
            w[k++] = v[i++];
        }

        while (j < r) {
            w[k++] = v[j++];
        }

        for (i = p; i < r; i++) {
            v[i] = w[i - p];
        }

    }

### Mergesort

Utiliza a funçao merge para ordenar o vetor. Consiste em ir dividindo o vetor principal em vetores menores até o momento que fica apenas um unico elemento. Depois, vai dando merge e ordenando os vetores menores e formando o vetor original, porém ordenado.

    int mergeSort (int p, int r, int v[]) {
        if (p < r - 1) {
            int q = (p + r) / 2;
            mergeSort(p, q, v);
            mergeSort(q, r, v);
            merge(p, q, r, v);
        }
    }

### Quicksort

    void quickSort (int p, int r, int v[]) {
        int q;

        if (p < r) {
            q = particao(p, r, v);
            quickSort(p, q - 1, v);
            quickSort(q + 1, r, v);
        }
    }

#### Partição (quicksort)

    int particao (int p, int r, int v[]) {
        int i, j, temp, pivo;
        pivo = v[r];
        j = p;

        for (i = p; i < r; i++) {
            if (v[i] < pivo) {
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
                j++;
            }
        }

        v[r] = v[j];
        v[j] = pivo;

        return j;
    }

### Countingsort

É uma forma de ordenação estável. Ela não utiliza comparações.

    void countingSort (int *vetor, int tamanho, int k) {
        int *aux, *saida;
        int i;

        aux = malloc((k + 1) * sizeof(int));
        saida = malloc(tamanho * sizeof(int));

        for (i = 0; i <= k; i++) {
            aux[i] = 0;
        }

        for (i = 0; i < tamanho; i++) {
            aux[vetor[i]]++;
        }

        for (i = 1; i <= k; i++) {
            aux[i] = aux[i] + aux[i - 1];
        }

        for (i = tamanho - 1; i >= 0; i--) {
            saida[aux[vetor[i]] - 1] = vetor[i];
            aux[vetor[i]]--;
        }

        for (i = 0; i < tamanho; i++) {
            vetor[i] = saida[i];
        }

        free(aux);
        free(saida);
    }

## Listas encadeadas

### Lista Simplesmente Encadeada

Não disponível.

### Lista Duplamente Encadeada

    typedef struct lista {
        char nome[40];
        char cpf[12];
        int idade;
        struct lista *prox;
        struct lista *ant;
    } Dados;

    Dados *criaLista() {
        return NULL;
    }

#### Criar

    Dados *criar(char *nome, char *cpf, int idade) {
        Dados *novo = (Dados *) malloc(sizeof(Dados));
        strcpy(novo->nome, nome);
        strcpy(novo->cpf, cpf);
        novo->idade = idade;
        novo->prox = NULL;
        novo->ant = NULL;

        return novo;
    }

#### Inserir

    Dados *inserir(Dados *lista, Dados *pessoa){
        if(lista != NULL) {
            lista->ant = pessoa;
        }

        pessoa->prox = lista;
        return pessoa;
    }

#### Imprimir

    void imprimir(Dados *lista) {
        Dados *aux = lista;

        while(aux != NULL) {
            puts(aux->nome);
            aux = aux->prox;
        }
    }

#### Consultar

    Dados *consultar(Dados *lista, char *cpf) {
        Dados *aux = lista;

        while(aux != NULL && strcmp(cpf, aux->cpf) != 0 ) {
            aux = aux->prox;
        }

        return aux;
    }

#### Imprimir Pessoa

    void imprimirPessoa(Dados *pessoa) {
        puts(pessoa->nome);
        puts(pessoa->cpf);
        printf("%d\n", pessoa->idade);
    }

#### Remover

    Dados *remover(Dados *lista, Dados *pessoa) {
        if(pessoa->ant == NULL) {
            Dados *aux = pessoa->prox;
            aux->ant = NULL;
            free(pessoa);
            return aux;
        } else {
            pessoa->ant->prox = pessoa->prox;

            if(pessoa->prox != NULL) {
                pessoa->prox->ant = pessoa->ant;
            }

            free(pessoa);
            return lista;
        }
    }



# 2º Bimestre


## Pilha

LIFO. Só pode remover os elemento que está no topo. O último que entrou.

### Opção 1: Encadeada

    typedef struct ItemPilha {
        int dado;
        struct ItemPilha *prox;
    } ItemPilha;

    typedef struct Pilha {
        ItemPilha *topo;
    } Pilha;

#### Create

    Pilha *create () {
        Pilha *p = malloc(sizeof(Pilha));
        p->topo = NULL;

        return p;
    }

#### Push

    void push (Pilha *p, int elemento) {
        ItemPilha *itemPilha = malloc(sizeof(ItemPilha));
        itemPilha->dado = elemento;

        if (!isEmpty(p)) {
            itemPilha->prox = p->topo;
        }

        p->topo = itemPilha;
    }

#### Pop

    int pop (Pilha *p) {
        if (!isEmpty(p)) {
            ItemPilha *itemPilha = p->topo;
            int dado = itemPilha->dado;
            p->topo = itemPilha->prox;
            free(itemPilha);
            return dado;
        } else {
            printf("Pilha já está vazia.\n");
        }
    }

#### Peek

    int peek (Pilha *p) {
        if (isEmpty(p)) {
            printf("A pilha está vazia. Não há elementos no topo\n");
        } else {
            return p->topo->dado;
        }
    }

#### isEmpty

    int isEmpty (Pilha *p) {
        return p->topo == NULL;
    }

### Opção 2: Sequencial

    #define TAM 3

    typedef struct Pilha {
        int dado[TAM];
        int topo;
    } Pilha;

#### Create

    Pilha *create () {
        Pilha *p = malloc(sizeof(Pilha));
        p->topo = -1;
        return p;
    }

#### Push

    void push (Pilha *p, int dado) {
        if (p->topo >= TAM - 1) {
            printf("Impossível adicionar novo elemento. A Pilha está totalmente cheia\n");
        } else {
            p->topo ++;
            p->dado[p->topo] = dado;
        }
    }

#### Peek

    int peek (Pilha *p) {
        if (isEmpty(p)) {
            printf("A lista está vazia, não existe elementos nela.\n");
        } else {
            int dado;
            dado = p->dado[p->topo];
            return dado;
        }
    }

#### Pop

    void pop (Pilha *p) {
        if (isEmpty(p)) {
            printf("A lista está vazia, não existe elementos nela.\n");
        } else {
            p->topo --;
        }
    }

#### isEmpty

    int isEmpty (Pilha *p) {
        return p->topo == -1;
    }


## Fila

FIFO. O primeiro elemento que foi inserido na lista, é o primeiro a sair, seguindo a ideia de uma fila de banco.

### Encadeada

    typedef struct ItemFila {
        int dado;
        struct ItemFila *prox;
    } ItemFila;

    typedef struct Fila {
        ItemFila *inicio;
        ItemFila *fim;
    } Fila;

#### Create

    Fila *create () {
        Fila *f = malloc(sizeof(Fila));
        f->inicio = NULL;
        f->fim = NULL;

        return f;
    }

#### Push

    void push (Fila *f, int elemento) {
        ItemFila *itemFila = malloc(sizeof(ItemFila));
        itemFila->dado = elemento;
        itemFila->prox = NULL;

        if (isEmpty(f)) {
            f->inicio = itemFila;
        } else {
            f->fim->prox = itemFila;
        }

        f->fim = itemFila;
    }

#### Pop

    int pop (Fila *f) {
        if (isEmpty(f)) {
            printf("Impossível remover elementos. A fila está vazia.\n");
        } else {
            ItemFila *itemFila = f->inicio;
            int dado = itemFila->dado;
            f->inicio = itemFila->prox;
            free(itemFila);

            return dado;
        }
    }

#### Peek

    int peek (Fila *f) {
        return f->inicio->dado;
    }

    int isEmpty (Fila *f) {
        return f->inicio == NULL;
    }

### Sequencial

    #define TAMANHO 10

    typedef struct Fila {
        int elemento[TAMANHO];
        int inicio, quantidadeElementos;
    } Fila;

#### Create

    Fila *create () {
        Fila *f = malloc(sizeof(Fila));
        f->inicio = 0;
        f->quantidadeElementos = 0;

        return f;
    }

#### Push

    void push (Fila *f, int elemento) {
        if (f->quantidadeElementos == TAMANHO) {
            printf("A fila está cheia. Não suporta novos elementos.\n");
        } else {
            f->elemento[(f->inicio + f->quantidadeElementos) % TAMANHO] = elemento;
            f->quantidadeElementos ++;
        }
    }

#### Pop

    int pop (Fila *f) {
        if (isEmpty(f)) {
            printf("Impossível remover elementos. A fila está vazia.\n");
        } else {
            int elemento = f->elemento[f->inicio];
            f->inicio = (f->inicio + 1) % TAMANHO;
            f->quantidadeElementos --;

            return elemento;
        }
    }

#### Peek

    int peek (Fila *f) {
        if (isEmpty(f)) {
            printf("Impossível consultar o dado do primeiro da fila. A fila está vazia.\n");
        } else {
            return f->elemento[f->inicio];
        }
    }

#### isEmpty

    int isEmpty (Fila *f) {
        return f->quantidadeElementos == 0;
    }



## Árvore binária de busca

    typedef struct No {
        struct No *esq;
        struct No *dir;
        int dado;
    } No;

#### Create

    No *create () {
        return NULL;
    }

#### Push

    void push (No **raiz, int elemento) {
        
        // Lista vazia

        if (*raiz == NULL) {
            *raiz = malloc(sizeof(No));
            (*raiz)->dado = elemento;
            (*raiz)->esq = NULL;
            (*raiz)->dir = NULL;
        }

        // Árvore populada. Elemento a ser inserido menor que raiz.

        if (elemento < (*raiz)->dado) {
            push(&((*raiz)->esq), elemento);
        }

        //  Árvore populada. Elemento a ser inserido mairo que raiz.

        if (elemento > (*raiz)->dado) {
            push(&((*raiz)->dir), elemento);
        }
    }

#### Search

    No *search (No *raiz, int elemento) {
        
        // Lista vazia
        
        if (raiz == NULL ) {
            printf("Não foi possível encontrar elemento.\n");
            return NULL;
        }

        // Árvore populada. Apenas existe um elemento que é a raiz.
        
        if (elemento == raiz->dado) {
            return raiz;
        }

        // Árvore populada. Elemento a ser buscado menor que raiz.
        
        if (elemento < raiz->dado) {
            return search(raiz->esq, elemento);
        }

        // Árvore populada. Elemento a ser buscado menor que raiz.
        
        if (elemento > raiz->dado) {
            return search(raiz->dir, elemento);
        }
    }

#### Menor valor da sub-arvore

    No *menorValor (No **raiz) {
        
        No *aux = *raiz;

        // Caso não exista árvore a esquerda
        
        if ((*raiz)->esq == NULL) {
            *raiz = (*raiz)->dir;
            return aux;
        }

        // Caso exista árvore a esquerda com valores menores
        
        else {
            return menorValor(&((*raiz)->esq));
        }
    }

#### Remover Nó

    void removerNo (No **raiz) {
        No *pos = *raiz;

        // O nó a ser removido não tem filhos. Esquerda e direita apontam para NULL.
        
        if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
            *raiz = NULL;
        }

        // O nó a ser removido não tem filhos apenas a esquerda.
        
        else if ((*raiz)->esq == NULL) {
            *raiz = (*raiz)->dir;
        }

        // O nó a ser removido não tem filhos apenas a direita.
        
        else if ((*raiz)->dir == NULL) {
            *raiz = (*raiz)->esq;
        }

        // O nó a ser removido tem os dois filhos
        
        else {
            No *pos = menorValor(&((*raiz)->dir));
            (*raiz)->dado = pos->dado;
        }

        free(pos);
    }

#### Remover

    int remover (No **raiz, int elemento) {
        
        // Lista vazia ou não existe o nó
        
        if (*raiz == NULL) {
            printf("Não foi possível encontrar elemento.\n");
            return 0;
        }

        // Nó a ser removido é a raiz
        
        if (elemento == (*raiz)->dado) {
            removerNo(raiz);
            return 1;
        }

        // Nó a ser removido é menor que raiz
        
        if (elemento < (*raiz)->dado) {
            return remover(&((*raiz)->esq), elemento);
        }

        // Nó a ser removido é maior que raiz
        
        if (elemento > (*raiz)->dado) {
            return remover(&((*raiz)->dir), elemento);
        }
    }

### Percorrer

#### Ordem

    void ordem(Arvore *raiz){
        if(raiz != NULL){
            pre_ordem(raiz->esq);
            printf("%i\n", raiz->dados);
            pre_ordem(raiz->dir);
        }
    }

#### Pré Ordem

    void pre_ordem(Arvore *raiz){
        if(raiz != NULL){
            printf("%i\n", raiz->dados);
            pre_ordem(raiz->esq);
            pre_ordem(raiz->dir);
        }
    }

#### Pos Ordem

    void pos_ordem(Arvore *raiz){
        if(raiz != NULL){
            pre_ordem(raiz->esq);
            pre_ordem(raiz->dir);
            printf("%i\n", raiz->dados);
        }
    }



## Tabela de dispersão

    typedef struct Aluno {
        long mat;
        char nome[80];
        char email[40];
    } Aluno;

    typedef struct No {
        Aluno dados;
        struct No *prox;
    } No;

    int hash (int mat) {
        return (mat % 100);
    }

#### Create

    No *criar_lista () {
        return NULL;
    }

#### Inserir Lista

    No *inserir_lista (No *l, Aluno a) {
        No *no = malloc(sizeof(No));
        no->dados = a;
        no->prox = l;
        l = no;
        return l;
    }

#### Consultar Lista

    No *consultar_lista (No *lista, long m) {
        No *no;
        for (no = lista; no != NULL; no = no->prox) {
            if (no->dados.mat == m) {
                return no;
            }
        }
        return NULL;
    }

#### Inserir

    void inserir (No **t, Aluno a) {
        int h = hash(a.mat);
        No *no;
        no = consultar_lista(t[h], a.mat);
        if (no == NULL) {
            t[h] = inserir_lista(t[h], a);
        } else {
            printf("\n\nMatricula ja cadastradada!!");
        }
    }

#### Alterar Lista

    No *alterar_lista (No *lista, long m) {
        No *no;
        char nome[80], email[40];
        for(no = lista; no != NULL; no = no->prox) {
            if (no->dados.mat == m) {
                printf("\nInforme o novo nome: ");
                fgets(nome, 80, stdin);
                strcpy(no->dados.nome, nome);
                printf("\nInforme o novo email: ");
                fgets(email, 40, stdin);
                strcpy(no->dados.email, email);
                return no;
            }
        }
        return NULL;
    }

#### Alterar

    void alterar (No **t, Aluno a) {
        int h = hash(a.mat);
        No *no;
        no = alterar_lista(t[h], a.mat);
        if (no == NULL) {
            printf("Nao encontrado");
        }
    }

#### Consultar

    void consultar (No **t, long m) {
        int h = hash(m);
        No *no;
        no = consultar_lista(t[h], m);
        if (no == NULL) {
            printf("\nElemento nao encontrado!");
        } else {
            printf("\nMatricula: %i", no->dados.mat);
            printf("\nNome: %s", no->dados.nome);
            printf("\nEmail: %s", no->dados.email);
        }
    }

#### Remover

    void remover (No **t, long m) {
        int h = hash(m);
        No *ant = NULL;
        No *no = t[h];
        
        while(no != NULL) {
            
            if(no->dados.mat == m) {
                
                if (ant == NULL) {
                    t[h] = no->prox;
                } else {
                    ant->prox = no->prox;
                }
                
                free(no);
            }

            ant = no;
            no = no->prox;
        }
    }