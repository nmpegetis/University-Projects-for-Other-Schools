/***************************************************************************************
Arxeio Epikefalidas	: ListE.h -to sigkekrimeno apotelei to arxeio protipo 
Syggrafeas			: Giota Kwnstantinou
Ana8ewrhsh			: D.Mhlios
                  Ena arxeio diepafhs gia oles tis ylopoihseis listas
****************************************************************************************/
#ifndef __POINTER__LISTE_ 
#define __POINTER__LISTE_

#include "TStoixeioyListasE.h" /*edo analoga tin efarmogi i to test 
 tou tipou stoixeiou mpainei to antoistixo .h tou tipou stoixeiou */

/*dhlwseis typwn*/
typedef struct info_node  * info_deikti;

typedef struct typos_komvou *typos_deikti;

/*dhlwseis synarthsewn*/

/*dhmioyrgia/katastrofi listas*/
info_deikti LIST_dimiourgia();
void LIST_katastrofi(info_deikti * linfo);

/*prakseis elegxoy*/
int	LIST_keni(const info_deikti  linfo);

/*prakseis prosbashs*/
void LIST_periexomeno(const info_deikti  linfo, const typos_deikti p, TStoixeioyListasE *val,int * error);
void LIST_allagi(info_deikti * const linfo, typos_deikti * const p, TStoixeioyListasE stoixeio,int * error);
void LIST_diadromi(const info_deikti  linfo, int * const error);

/*prakseis eisagwgh-diagrafh*/
void LIST_eisagogi(info_deikti * const linfo, TStoixeioyListasE stoixeio,
					typos_deikti prodeiktis, int *error);
void LIST_diagrafi(info_deikti * const linfo, typos_deikti *deiktis, int * const error);

/* Epilogh Kombou */
void LIST_epomenos(const info_deikti  linfo, typos_deikti * const p, int * const error);
void LIST_proigoymenos(const info_deikti linfo, typos_deikti * const p, int * const error);
void LIST_first(const info_deikti  linfo, typos_deikti * const first, int * const error);
void LIST_last(const info_deikti  linfo, typos_deikti * const last, int * const error);

/*prakseis anazhthshs*/

void LIST_anazitisi(const info_deikti  linfo, TStoixeioyListasE stoixeio,
					typos_deikti *prodeiktis, int *vrethike);

#endif /*#ifndef __POINTER__LISTE_ */
