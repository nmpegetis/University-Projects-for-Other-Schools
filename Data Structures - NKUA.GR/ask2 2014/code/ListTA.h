/***************************************************************************************
Arxeio Epikefalidas	: ListTA.h -to sigkekrimeno apotelei to arxeio protipo 
Syggrafeas			: Giota Kwnstantinou
Skopos			    : Ylopoihsh me deiktes, ATD Syndedemenh Lista
Ana8ewrhsh			: D.Mhlios
                  Ena arxeio diepafhs gia oles tis ylopoihseis listas
****************************************************************************************/
#ifndef __LISTTA_ 
#define __LISTTA_

#include "TStoixeioyListasTA.h" /*edo analoga tin efarmogi i to test 
 tou tipou stoixeiou mpainei to antoistixo .h tou tipou stoixeiou */

/*dhlwseis typwn*/
typedef struct info_nodeTA  * info_deiktiTA;

typedef struct typos_komvouTA *typos_deiktiTA;

/*dhlwseis synarthsewn*/

/*dhmioyrgia/katastrofi listas*/
info_deiktiTA LIST_dimiourgiaTA();
void LIST_katastrofiTA(info_deiktiTA * linfo);

/*prakseis elegxoy*/
int	LIST_keniTA(const info_deiktiTA  linfo);

/*prakseis prosbashs*/
void LIST_periexomenoTA(const info_deiktiTA  linfo, const typos_deiktiTA p, TStoixeioyListasTA *val,int * error);
void LIST_allagiTA(info_deiktiTA * const linfo, typos_deiktiTA * const p, TStoixeioyListasTA stoixeio,int * error);
void LIST_diadromiTA(const info_deiktiTA  linfo, int * const error);

/*prakseis eisagwgh-diagrafh*/
void LIST_eisagogiTA(info_deiktiTA * const linfo, TStoixeioyListasTA stoixeio,
					typos_deiktiTA prodeiktis, int *error);
void LIST_diagrafiTA(info_deiktiTA * const linfo, typos_deiktiTA *deiktis, int * const error);

/* Epilogh Kombou */
void LIST_epomenosTA(const info_deiktiTA  linfo, typos_deiktiTA * const p, int * const error);
void LIST_proigoymenosTA(const info_deiktiTA linfo, typos_deiktiTA * const p, int * const error);
void LIST_firstTA(const info_deiktiTA  linfo, typos_deiktiTA * const first, int * const error);
void LIST_lastTA(const info_deiktiTA  linfo, typos_deiktiTA * const last, int * const error);

/*prakseis anazhthshs*/

void LIST_anazitisiTA(const info_deiktiTA  linfo, TStoixeioyListasTA stoixeio,
					typos_deiktiTA *prodeiktis, int *vrethike);

#endif /*#ifndef __LISTTA_ */
