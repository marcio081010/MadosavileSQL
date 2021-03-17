#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define WARNINGS \
	"mysql_num_rows", "mysql_fetch_array", \
	"SQL syntax error", "ODBC SQL Server Driver", \
	"mysql_fetch_assoc", "Warning: ", \
	"mysql_result", "mysql_query", \
	"array_merge", "preg_match", \
	"SQL Syntax", "mysql_numrows", \
	"mysql_preg_match"

#define say printf
#define die(STR,ERROR) {printf(STR);exit(ERROR);}
#define MAX 256
#ifndef TRUE
#define TRUE 0
#endif
#ifndef FALSE
#define FALSE 1
#endif

typedef struct {
	char *input;
	char *output;
	int threads;
} instance_t;

typedef struct {
	int index;
	char *url;
} param_t;

typedef struct {
	status int não assinado;
	comprimento int não assinado;
	conteúdo de char *sem assinatura;
} http_request_t;

struct typedef {
	porta int não assinada;
	comprimento int não assinado;
	conteúdo de char *sem assinatura;
	char *domínio não assinado;
	char *caminho não assinado;
} url_t;

instance_t *instância;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

url_t estática  *http_request_parse_url(const char  *url);
http_request_t estática *http_request_free(http_request_t *solicitação);
http_request_t estática  *http_get_request(const  char *url);
vazio estático *scanner (vazio *tparam);
núcleo vazio estático (vazio);
vazio estático  save_vuln_link (const char *link);
vazio estático  show_banner(vazio);

int principal (int argc, char **argv) {
	se (argc != 4) {
		show_banner();
		dizer(" Use... \n %s lista de links.txt arquivo de saída.txt número de threads\n\n", argv[0]);
	}
	Mais {
		se (!( exemplo = (instance_t *) malloc(sizeof(instance_t))))
			die("Error to alloc memory.\n", 1)
		if (!(instance->input = (char *) malloc(sizeof(char)*strlen(argv[1])+1)))
			die("Error to alloc memory.\n", 1)
		memset(instance->input, '\0', sizeof(char)*strlen(argv[1])+1);
		memcpy(instance->input, argv[1], strlen(argv[1]));
		if (!(instance->output = (char *) malloc(sizeof(char)*strlen(argv[2])+1)))
			die("Error to alloc memory.\n", 1)
		memset(instance->output, '\0', sizeof(char)*strlen(argv[2])+1);
		memcpy(instance->output, argv[2], strlen(argv[2]));
		instance->threads = atoi(argv[3]);
		if (!instance->input || !instance->output || !instance->threads) 
			die("Invalid value.\n", 0)
		else {
			show_banner();
			core();
		}
	}
	return (0);
}

vazio estático *scanner (vazio *tparam) {
	param_t *param =(param_t *) tparam;
	se (!param) retornar (NULL);
	se (!param->url) retornar (NULL);
	dizer(" [% d] -> %s\n", param->índice, param->url);
	http_request_t *solicitação = http_get_request(param->url);
	se (solicitação != NULL) {
		se (solicitação->status == TRUE)
			se (solicitar->conteúdo) {
				char *sql_injection_warning_list [] = { Avisos, NULO };
				para (int i=0; sql_injection_warning_list[i]!=NULL; i++) {
					se (strstr(request->content, sql_injection_warning_list[i]) {
						pthread_mutex_lock(&mutex);
						save_vuln_link(param->url);
						pthread_mutex_unlock(&mutex);
						Quebrar;
					}
				}
			}
		http_request_free(solicitação);
	}
}

vazio estático  save_vuln_link (const char *link) {
 ARQUIVO *fp = NULL;
	se (!( fp = fopen(instância->saída,  "a+" )))
		morrer("Erro para abrir arquivo de saída. \n", 1);
	fprintf  (fp, %s\n", link);
	fclose(fp);
}

núcleo vazio estático (vazio) {
 ARQUIVO *fp = NULL;
	linha char [MAX+1];
	pthread_t fio **;
	contador int = 0, resultado = 0;
	se (!( fp = fopen(instância->entrada,  "r" )))
		morrer("Arquivo de entrada não existe. \n", 0);
	se (!( rosca = (pthread_t **) malloc((tamanho (pthread_t)*instância->threads)+1 )))
			morrer("Erro para alloc memória de rosca. \n", 1)
	se (pthread_mutex_init(&mutex, NULL) != 0)
		morrer("Erro para inicializar mutex. \n", 1)
	dizer("\n Começou... \n\n" );
	enquanto (1) {
		para (int i=0; i<instance->threads; i++) {
			memset(linha,  \0', MAX+1);
 resultado = fgets(linha, MAX, fp);
			se (!resultado) quebrar;
			para (int a=0; linha[a]!=\0'; a++)
				se (linha[a] ==  \ \n' )
 linha[a] =  \0' ;
			param_t *param;
			se (!( param =(param_t *) malloc(sizeof(param_t))))
				morrer("Erro à memória alloc. \n", 1);
			se (!( param->url =(char *) malloc((sizeof(char)*strlen(linha)+1)))
				morrer("Erro à memória alloc. \n", 1);
			memset(param->url  , \0',(sizeof(char)*strlen(linha)+1);
			memcpy(param->url, linha, strlen(linha));
 param->índice = contador++;
			pthread_create(&thread[i], NULL, &scanner,(vazio *)param);
		}
		se (!resultado) quebrar;
		para (int i=0; i<instance->threads; i++)
			pthread_join(thread[i], NULL);
	}
	fclose(fp);
	dizer("\n Acabado. \n\n" );
	pthread_exit);
	pthread_mutex_destroy(&mutex);
}

url_t estática  *http_request_parse_url(const char  *url) {
	se (!url) retornar (url_t *) NULL;
	
	url_t *new_url = (url_t *) malloc(tamanhos(url_t));
	se (!new_url) 
		retorno (url_t *) NULL;
	
 new_url->porta = 80;
 new_url->comprimento = 0;
 new_url->conteúdo = NULL;
 domínio new_url-> = NULL;
 new_url->caminho = NULL;
	
	se (!( new_url->conteúdo = (char *)  malloc(strlen(url) + 1))) {
		livre(new_url);
		retorno (url_t *) NULL;
	}
	
	memset(new_url->conteúdo  , \0', strlen(url) + 1);
	memcpy(new_url->conteúdo, url, strlen(url));
 new_url->comprimento = strlen(new_url->conteúdo);
	
	se (!new_url-gt;comprimento > 0 || ! strlen(new_url->conteúdo) > 0) {
		se (new_url->conteúdo != NULL) 
			conteúdo gratuito(new_url->);
		livre(new_url);
		retorno (url_t *) NULL;
	}
	
	int não assinado  start_pointer = 0;
	char não assinado *u_ptr = new_url->conteúdo;
	se (strstr(u_ptr,  "" )) {
		se (!( u_ptr[0] ==  'h'  & amp;& u_ptr[1] ==  't'  && u_ptr[2] ==  't'  && u_ptr[3] ==  'p'  && 
 u_ptr[4] ==  '  & amp;& u_ptr[5] ==  /'  & amp;& u_ptr[6] == '/')) {
			conteúdo gratuito(new_url->);
			livre(new_url);
			retorno (url_t *) NULL;
		} Mais 
 start_pointer = strlen("http://" );
	}
	
	u_ptr += start_pointer;
	contador de int não assinado = 0;
	char não assinado  *c_port = NULL;
	char não assinado  *p_ptr = NULL;
	se ((p_ptr = strstr  (u_ptr"" ") != NULL && ++p_ptr) {
		se ((c_port = (char *) malloc(tamanho (charnão assinado ) * 10)) != NULL) {
			para (int a=0; p_ptr[a]!=\0'; a++) {
 contador = 0;
				para (int b='0'; b<='9'  ; b++)
					se (p_ptr[a] == b)
 contador++;
				se (!contador > 0) {
 c_port[a] =  '\0' ;
					Quebrar;
				}
				c_port[a] = p_ptr[a];
			}
			se (c_port != NULL)
 new_url->porta = (int) strtol(c_port, NULL, 10);
			livre(c_port);
		}
	}
	
	se (new_url->porta == 0)
 new_url->porta = 80;
	
	se (!new_url->porta > 0) {
		se (c_port)
			livre(c_port);
		se (new_url->conteúdo != NULL) 
			conteúdo gratuito(new_url->);
		livre(new_url);
		retorno (url_t *) NULL;
	}
	
	char não assinado  *c_domain = NULL;
	se ((c_domain =(char *)  malloc(tamanho (charnão assinado ) * (256*2))!= NULL) {
		memset(c_domain,  \0', sizeof( charnãoassinado ) * (256*2));
		para (int d=0; d<256; d++) {
 contador = 0;
			para (int a='a', b='A', c='0'; a<='z'; a++,b++) {
				se (u_ptr[d] == a || u_ptr[d] == b || u_ptr[d] == c || 
 u_ptr[d] ==  '  || u_ptr[d] == '-')
 contador++;
				se (c <=  '9' )
					b++;
			}
			se (contador == 0) {
 c_domain[d] =  '\0' ;
				se ((new_url->domínio = (char *) malloc(sizeof( charnão assinado ) * (d + 1))!= NULL) {
					memset(new_url->domínio  , \0', sizeof (charnão assinado ) * (d + 1));
					memcpy(domínio new_url->c_domain, d);
				}
				Quebrar;
			}
			c_domain[d] = u_ptr[d];
		}
		livre(c_domain);
	}
	
	se (new_url->domínio == NULL) {
		se (c_domain)
			livre(c_domain);
		se (c_port)
			livre(c_port);
		se (new_url->conteúdo != NULL) 
			conteúdo gratuito(new_url->);
		livre(new_url);
		retorno (url_t *) NULL;
	}
	
	char não assinado  *c_path = NULL;
	se ((c_path = ( char *) malloc (tamanho (charnão assinado ) * (new_url->comprimento + (256*2)) )) != NULL) {
		memset(c_path,  \0', sizeof( charnão assinado ) * (new_url->comprimento + (256*2)));
 contador = 0;
		para (int a=0; u_ptr[a]!=\0'; a++) {
			se (u_ptr[a] == '/') {
 contador++;
				Quebrar;
			}
		}
		se (contador > 0) {
			char não assinado  *p_ptr = strstr(u_ptr, "/");
			se (p_ptr != NULL) {
				int a não assinado = 0;
				para (; p_ptr[a]!= \0'; a++)
					c_path[a] = p_ptr[a];
				se ((new_url->path = (char *) malloc(sizeof( charnão assinado ) * (a + 1))) != NULL) {
					memset(new_url->caminho  , \0', sizeof( charnão assinado ) * (a + 1));
					memcpy(new_url->caminho, c_path, a);
				}
			}
		} Mais {
			barra de char não assinada [] = = "/";
			se ((new_url->path = (char *) malloc(sizeof( charnão assinado ) *(strlen(bar) + 1))!= NULL) {
				memset(new_url->caminho  , \0', sizeof( charnão assinado ) * (strlen(bar) + 1));
				memcpy(new_url->caminho, bar, strlen(bar));
			}
		}
		livre(c_path);
	}
	
	se (new_url->caminho == NULL) {
		se (c_path)
			livre(c_path);
		se (c_domain)
			livre(c_domain);
		se (c_port)
			livre(c_port);
		se (new_url->conteúdo != NULL) 
			conteúdo gratuito(new_url->);
		livre(new_url);
		retorno (url_t *) NULL;
	}
	
	se (new_url != NULL)
		new_url de retorno;
	
	retorno (url_t *) NULL;
}

#definir FREE_URL_FORMATED \
	url_formated->port = 0;\
 url_formated->comprimento = 0;\
	se (url_formated->conteúdo != NULL)\
 url_formated->conteúdo = NULL;\
	se (url_formated->domínio != NULL)\
 domínio url_formated->= NULL;\
	se (url_formated->path != NULL)\
		url_formated->path = NULL
http_request_t estática  *http_get_request(const  char *url) {
	se (!url) retornar (http_request_t *) NULL;
	
	url_t *url_formated = http_request_parse_url(url);
	se (url_formated == NULL) 
		retorno (http_request_t *) NULL;
	
	struct hostent *host_information = gethostbyname(url_formated->domínio);
	se (host_information == NULL) {
		FREE_URL_FORMATED;
		retorno (http_request_t *) NULL;
	}
	
	instruir sockaddr_in endereço;
 Endereço. sin_family = AF_INET;
 Endereço. sin_port = htons(url_formated->porta);
 Endereço. sin_addr. s_addr =*(longo sem assinatura *) host_information->h_addr_list[0];
	
	meia int =(int)(-1);
	se ((meia = soquete(AF_INET, SOCK_STREAM, 0)) < 0) {
		FREE_URL_FORMATED;
		retorno (http_request_t *) NULL;
	}
	
	const struct timeval timeout = { . tv_sec=3. . tv_usec=0};
	setsockopt(meia, SOL_SOCKET, SO_RCVTIMEO,(char *)&timeout, sizeof(timeout));
	
	int resultado =(int)(-1);
	se ((resultado = conectar(meia, (struct sockaddr *)&endereço, sizeof(endereço)) < 0) {
		FREE_URL_FORMATED;
		fechar(meia);
		retorno (http_request_t *) NULL;
	}
	
	char sem assinatura  *cabeçalho = NULL;
	se (!( cabeçalho = (char *) malloc(tamanho (charnão assinado) * ((256*5) + strlen(url) + 1)))) {
		FREE_URL_FORMATED;
		fechar(meia);
		retorno (http_request_t *) NULL;
	}
	memset(cabeçalho,  \0', sizeof( charnãoassinado ) * ((256*5) + strlen(url) + 1));
	sprintf(cabeçalho, 
		"GET %s' HTTP/1.1\r\n"
		"Host: %s\r\n"
		 "Conexão: close\r\n\r\n", url_formated->path, url_formated->domínio);
	
	se (enviar(meia, cabeçalho, strlen(cabeçalho), 0) == -1) {
		FREE_URL_FORMATED;
		livre(cabeçalho);
		fechar(meia);
		retorno (http_request_t *) NULL;
	}
	
 resultado = 0;
	int não assinado  is_going = 1;
	int não assinado  total_length = 0;
	char  *response não assinado = (char *) malloc(tamanho (charnão assinado) * (256*2));
	char não assinado  *response_final =(char *)  malloc(tamanho (charnão assinado) * (256*2));
	
	se (!resposta || !response_final) {
		FREE_URL_FORMATED;
		livre(cabeçalho);
		se (resposta)
			livre(resposta);
		se (response_final)
			livre(response_final);
		fechar(meia);
		retorno (http_request_t *) NULL;
	}
	
	memset  (resposta, \0', sizeof( charnão assinado ) * (256*2));
	memset(response_final,  \0', sizeof( charnãoassinado ) * (256*2));
	
	enquanto (is_going) {
 resultado = recv(meia, resposta, (tamanho (charnãoassinado ) * (256*2)) - 1, 0);
		se (resultado == 0 || resultado < 0)
			is_going = 0;
		Mais {
			se ((response_final = (char *) nãoassinado (response_final, total_length + 
				(tamanhos(char não assinado ) * (256*2)))!= NULL) {
				memcpy(&response_final[total_length], resposta, resultado);
 total_length += resultado;
			}
		}
	}
	
	int não assinado  result_flag = FALSO;
	http_request_t *solicitação = (http_request_t *) malloc(tamanhos(http_request_t));
	se (solicitação != NULL) {
		memset(solicitação, 0, sizeof(http_request_t));
 solicitação->status = FALSO;
 solicitação->comprimento = 0;
 solicitação->conteúdo = NULL;
		
		se (total_length > 0) {
 solicitação->comprimento = total_length;
			se ((request->content = (char *) malloc(sizeof( charnão assinado ) * (request->comprimento+1))) != NULL) {
				memset(request->content,  \0', sizeof( charnãoassinado ) * (request->comprimento+1));
				memcpy(request->conteúdo, response_final, request->comprimento);
 solicitação->status = TRUE;
				result_flag = TRUE;
			}
		}
	}
	
	fechar(meia);
	livre(cabeçalho);
	livre(resposta);
	livre(response_final);
	
 url_formated->porta = 0;
 url_formated->comprimento = 0;
	se (url_formated->conteúdo)
		conteúdo gratuito(url_formated->);
	se (url_formated->domínio)
		livre(url_formated->domínio);
	se (url_formated->caminho)
		livre(url_formated->caminho);
	livre(url_formated);
	
	se (result_flag == TRUE)
		solicitação de retorno;
	Mais {
		se (solicitação != NULL)
			livre(solicitação);
	}
	
	retorno (http_request_t *) NULL;
}

http_request_t estática  *http_request_free(http_request_t *solicitação) {
	se (!solicitar) retornar (http_request_t *) NULO;
	
 solicitação->comprimento = 0;
 solicitação->status = FALSO;
	grátis(solicitação->conteúdo);
	livre(solicitação);
	
	retorno (http_request_t *) NULL;
}

vazio estático  show_banner(vazio) {
dizer (\ \
   
 By: $$Marcio Vinicius$$\n\
                    Good Job to all");
}
