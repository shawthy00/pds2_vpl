

/*

Gerencia o fluxo completo de uma partida do jogo da velha, coordenando os dois jogadores e o tabuleiro.

Atributos:

    Tabuleiro tabuleiro: instância do tabuleiro utilizado na partida.
    Jogador jogador1: primeiro jogador.
    Jogador jogador2: segundo jogador.
    Jogador* atual: ponteiro para o jogador cuja vez é a atual.

Métodos:

    Partida(std::string jogador1, std::string jogador2): Método construtor que inicializa os dois jogadores com seus respectivos nomes e define o jogador inicial (quem começa jogando).

    Jogador& getJogadorAtual(): Retorna uma referência para o jogador cuja vez é a atual.

    void executarJogada(int linha, int coluna): Executa a jogada do jogador atual na posição (linha, coluna) do tabuleiro, seguindo a lógica abaixo:
        Se a jogada for válida: registra o símbolo do jogador atual no tabuleiro e alterna a vez para o outro jogador;
        Se a jogada for inválida: exibe a mensagem "Jogada invalida!\n" e mantém a vez do mesmo jogador.
        No método executarJogada adicione o comentário "// Jogada validada sequencial e alternada via llm".

    char statusPartida(): Retorna o estado atual da partida consultando o tabuleiro. Os valores possíveis são 'X', 'O', 'E' ou 'P' (conforme definido em verificarEstadoPartida()).

    void exibirPartida(): Exibe o estado atual do tabuleiro chamando o método imprimir() do tabuleiro.


    */