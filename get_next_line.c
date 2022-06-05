/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:35:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/05 20:35:53 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *GET NEXT LINE
 * O objetivo dessa função é imprimir o conteúdo de um arquivo de texto linha por linha com auxilio da funcao
 * read, aqui só será liberada a utilização das funcoes READ , MALLOC , FREE
 * Esse é meu primeiro esboço de como abordar o caso da GNL.
 *
 * A função Read tem os seguintes parametros "ssize_t read(int fd, void *buf, size_t count)"
 *
 * File descriptors só existem acima de 0 logo se FD < 0 deve retornar NULL
 * Se nao tivermos linhas o programa deve retornar NULL
 * Se o Buffersize for menor do que zero, retornamos NULL (se for zero tbm?)
 * Se read retornar -1 retornamos NULL
 *
 * A ideia aqui é que não podemos ler o arquivo novamente do inicio 
 * de onde paramos, logo se tiver um /n no meio do nosso
 * buffer precisamos guardar a informação depois dele para ser utilizada, para isso podemos usar uma
 * variavel do tipo Static
 * ----------------------------
 * Fazemos StrJoin de ReadBuffer(RESULTADO DE READ) para um StringBuffer 
 * Procuramos um /n no StringBuffer (podemos usar strchr)
 * NÃO -> faça strjoin para Se leia novamente -> encontrou o /n agora?
 * SIM -> strjoin de tudo antes do /n e tudo que esta depois continua na variavel statica a leitura continua
 * ate encontrarmos o proximo /n.
 * ----------------------------
 * Questões que me vem a cabeça
 * Se o buffer tiver mais do que um /n? criamos uma regra especifica pra isso?
 *
 *
 * Lembrar -
 * If N Def BUFFER_SIZE 42
 */
