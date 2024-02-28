#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - the environmtal variables are included here
 * @var: the string of the environment variable is taken by this
 * @inayofuata: shows to the following node
 */
typedef struct list
{
	char *var;
	struct list *inayofuata;
} list_t;

void c_kutoka(char **uzi, list_t *mzngr);
int _kuexecve(char **z, list_t *mzngr, int hes);
size_t pata_line(char **uzi);
void *_urealloc(void *onyeshi, unsigned int ukubwa_zamani,
		unsigned int ukubwa_mpya);
char *_niwhich(char *uzi, list_t *mzngr);
char *_uziaddto(char *htma, char *uziadd);
int _uzicmp(char *z1, char *z2);
char *_uzikopi(char *htma, char *uziadd);
char *_uzirudf(char *uzi);
char **_uzi_tok(char *uzi, char *chamb);
char *ignore_chamb(char *uzi, char chamb);
int t_ukubwa(char *uzi, char chamb);
int t_uziure(char *uzi, int naf, char chamb);
int c_t_ukubwa(char *uzi, char chamb);
char **c_uzi_tok(char *uzi, char *chamb);
void frii_dabo_ptr(char **uzi);
char *integer_kwenda_string(int hesabu);
int hesure(int h);
char *c_achana(char *uzi);
void isiyo_ingiliwakati(list_t *mzngr);
char *c_uziaddto(char *htma, char *uziadd);
int c_pangaenv(list_t **mzngr, char *jina, char *dirpath);
void cd_tu(list_t *mzngr, char *yasasa);
int cd_utekelezaji(list_t *mzngr, char *yasasa, char *dirpath, char *uzi,
		int hes);
int _cd(char **uzi, list_t *mzngr, int hes);
char *c_uzirudf(char *uzi, int rt);
char *pata_env(char *uzi, list_t *mzngr);
size_t print_orodha(list_t *k);
list_t *ongeza_mwisho_node(list_t **kichwa, char *uzi);
int futa_nodeint_kwenye_faharisi(list_t **kichwa, int faharisi);
void linked_listi_huru(list_t *list);
void hai_patikani(char *uzi, int v_h, list_t *mzngr);
void haiwezi_kucd_kwenye(char *uzi, int v_h, list_t *mzngr);
void namba_isiyohalali(char *uzi, int v_h, list_t *mzngr);
int tafuta_mzngr(list_t *mzngr, char *uzi);
int _ondoapangaenv(list_t **mzngr, char **uzi);
int _pangaenv(list_t **mzngr, char **uzi);
int _ku_atoyi(char *ng);
int _kutoka(char **uzi, list_t *mzngr, int hes, char **amri);
list_t *mzngr_linked_list(char **mzngr);
int _mzngr(char **uzi, list_t *mzngr);
void Ctrl_na_c(int h);
int kijenzi_chandani(char **tokeni, list_t *mzngr, int hes, char **amri);
char *achanana_space(char *uzi);
void Ctrl_na_d(int rodh, char *amri, list_t *mzngr);
int prompti(char **mz);


#endif /* SHELL_H */
