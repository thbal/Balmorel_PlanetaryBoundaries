* PB add-on. Added by Théo Balanza

$onmulti
$if     EXIST '../data/PB_LCA_DATA.inc' $INCLUDE         '../data/PB_LCA_DATA.inc';
$if not EXIST '../data/PB_LCA_DATA.inc' $INCLUDE '../../base/data/PB_LCA_DATA.inc';
$offmulti

$onmulti
$if     EXIST '../data/PB_THRESHOLDS_DATA.inc' $INCLUDE         '../data/PB_THRESHOLDS_DATA.inc';
$if not EXIST '../data/PB_THRESHOLDS_DATA.inc' $INCLUDE '../../base/data/PB_THRESHOLDS_DATA.inc';
$offmulti





