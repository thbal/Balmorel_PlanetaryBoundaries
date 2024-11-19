PARAMETER   ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET);
PARAMETER   IM_CO2_prod_elec(G) "CO2eq emission for the production of 1 kWh by unit G)"; 
PARAMETER   IM_CO2_prod_heat(G) "CO2eq emission for the production of 1 MJ by unit G)"; 
PARAMETER   IM_CO2_constr(G)   "CO2eq emission for the construction of 1 MW of unit G ";


*The following specify relation between GDTech group and GDFuel
ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET) = YES $(GDATA(G,'GDTECHGROUP') EQ PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'GROUP_TECH') AND GDATA(G,'GDFUEL') EQ PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'FUEL') AND GDATA(G,'GDTYPE') EQ PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'Generation_type'))

*The following attributes LCA values to each generator based in its GDTECHGROUP, GDFUEL and GDTYPE
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_CO2_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_CO2_prod_elec');
		IM_CO2_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_CO2_prod_heat');
		IM_CO2_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_CO2_constr');
    );
);

*Ozone depletion
PARAMETER   IM_Ozone_depletion_prod_elec(G) "CFC11eq emission for the production of 1 kWh by unit G)"; 
PARAMETER   IM_Ozone_depletion_prod_heat(G) "CFC11eq emission for the production of 1 MJ by unit G)"; 
PARAMETER   IM_Ozone_depletion_constr(G)   "CFC11eq emission for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_Ozone_depletion_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Ozone_depletion_prod_elec');
		IM_Ozone_depletion_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Ozone_depletion_prod_heat');
		IM_Ozone_depletion_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_Ozone_depletion_constr');
    );
);

*Land use
PARAMETER   IM_LU_prod_elec(G) "Pt emission for the production of 1 kWh by unit G)"; 
PARAMETER   IM_LU_prod_heat(G) "Pt emission for the production of 1 MJ by unit G)"; 
PARAMETER   IM_LU_constr(G)   "Pt emission for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_LU_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_LU_prod_elec');
		IM_LU_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_LU_prod_heat');
		IM_LU_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_LU_constr');
    );
);

*Water use
PARAMETER   IM_WU_prod_elec(G) "m3 deprivation impact for the production of 1 kWh by unit G)"; 
PARAMETER   IM_WU_prod_heat(G) "m3 deprivation impact for the production of 1 MJ by unit G)"; 
PARAMETER   IM_WU_constr(G)   "m3 deprivation impact for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_WU_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_WU_prod_elec');
		IM_WU_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_WU_prod_heat');
		IM_WU_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_WU_constr');
    );
);

*Eutrophication freshwater
PARAMETER   IM_Eutrophication_freshwater_prod_elec(G) "kg P equivalent emission for the production of 1 kWh by unit G)"; 
PARAMETER   IM_Eutrophication_freshwater_prod_heat(G) "kg P equivalent emission for the production of 1 MJ by unit G)"; 
PARAMETER   IM_Eutrophication_freshwater_constr(G)   "kg P equivalent emission for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_Eutrophication_freshwater_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Eutrophication_freshwater_prod_elec');
		IM_Eutrophication_freshwater_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Eutrophication_freshwater_prod_heat');
		IM_Eutrophication_freshwater_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_Eutrophication_freshwater_constr');
    );
);

*Ecotoxicity freshwater
PARAMETER   IM_Ecotoxicity_freshwater_prod_elec(G) "impact in CTU  for the production of 1 kWh by unit G)"; 
PARAMETER   IM_Ecotoxicity_freshwater_prod_heat(G) "impact in CTU for the production of 1 MJ by unit G)"; 
PARAMETER   IM_Ecotoxicity_freshwater_constr(G)   "impact in CTU for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_Ecotoxicity_freshwater_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Ecotoxicity_freshwater_prod_elec');
		IM_Ecotoxicity_freshwater_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Ecotoxicity_freshwater_prod_heat');
		IM_Ecotoxicity_freshwater_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_Ecotoxicity_freshwater_constr');
    );
);

*Particulate Matter
PARAMETER   IM_PM_prod_elec(G) "disease incidence for the production of 1 kWh by unit G)"; 
PARAMETER   IM_PM_prod_heat(G) "disease incidence for the production of 1 MJ by unit G)"; 
PARAMETER   IM_PM_constr(G)   "disease incidence for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_PM_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_PM_prod_elec');
		IM_PM_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_PM_prod_heat');
		IM_PM_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_PM_constr');
    );
);

*Resource use
PARAMETER   IM_Resource_prod_elec(G) "kg of Sb equivalent for the production of 1 kWh by unit G)"; 
PARAMETER   IM_Resource_prod_heat(G) "kg of Sb equivalent for the production of 1 MJ by unit G)"; 
PARAMETER   IM_Resource_constr(G)   "kg of Sb equivalent for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_Resource_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Resource_prod_elec');
		IM_Resource_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Resource_prod_heat');
		IM_Resource_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_Resource_constr');
    );
);

*Acidification
PARAMETER   IM_Acidification_prod_elec(G) "mol of H+ equivalent for the production of 1 kWh by unit G)"; 
PARAMETER   IM_Acidification_prod_heat(G) "mol of H+ equivalent for the production of 1 MJ by unit G)"; 
PARAMETER   IM_Acidification_constr(G)   "mol of H+ equivalent for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_Acidification_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Acidification_prod_elec');
		IM_Acidification_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Acidification_prod_heat');
		IM_Acidification_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_Acidification_constr');
    );
);

*Ionising radiation
PARAMETER   IM_Radiation_prod_elec(G) "kBq U-235 equivalent for the production of 1 kWh by unit G)"; 
PARAMETER   IM_Radiation_prod_heat(G) "kBq U-235 equivalent for the production of 1 MJ by unit G)"; 
PARAMETER   IM_Radiation_constr(G)   "kBq U-235 equivalent for the construction of 1 MW of unit G ";
LOOP((G, TECH_GROUP, FFF, PB_GDTYPE_SET),
    IF (ILCA(G,TECH_GROUP,FFF, PB_GDTYPE_SET),
        IM_Radiation_prod_elec(G) = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Radiation_prod_elec');
		IM_Radiation_prod_heat(G)  = PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET, 'LCA_Radiation_prod_heat');
		IM_Radiation_constr(G)= PB_LCA_DATA(TECH_GROUP, FFF, PB_GDTYPE_SET,'LCA_Radiation_constr');
    );
);

*CCS power plants
*elec only
*Climate change
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=0.172621612;
$ifi %CCS%==yes IM_CO2_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=0.172621612;

*Ozone depletion

$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=1.0072E-07;
$ifi %CCS%==yes IM_Ozone_depletion_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=1.0072E-07;


*Land usage
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=0.211679555;
$ifi %CCS%==yes IM_LU_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=0.211679555;

*Water usage
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=0.037216977;
$ifi %CCS%==yes IM_WU_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=0.037216977;

*Eutrophication freshwater
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=1.34191E-05;
$ifi %CCS%==yes IM_Eutrophication_freshwater_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=1.34191E-05;

*Ecotoxicity freshwater
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=6.012688197;
$ifi %CCS%==yes IM_Ecotoxicity_freshwater_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=6.012688197;

*Particulate matter
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=4.06093E-09;
$ifi %CCS%==yes IM_PM_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=4.06093E-09;

*Acidification
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=0.002183073;
$ifi %CCS%==yes IM_Acidification_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=0.002183073;

*Resource use
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-51_SS-10-MW_Y-2020')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-53_SS-10-MW_Y-2030')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-54_SS-10-MW_Y-2040')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-55_SS-10-MW_Y-2050')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-61_LS-100-MW_Y-2030')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-62_LS-100-MW_Y-2040')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_CC_NGASCCS_CND_E-63_LS-100-MW_Y-2050')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-37_SS-5-MW_Y-2020')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-39_SS-5-MW_Y-2030')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2040')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-40_SS-5-MW_Y-2050')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-42_LS-40-MW_Y-2020')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-43_LS-40-MW_Y-2030')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2040')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_GT_NGASCCS_CND_E-44_LS-40-MW_Y-2050')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_ENG_NGASCCS_CND_E-47_Y-2020')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_ENG_NGASCCS_CND_E-48_Y-2030')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_ENG_NGASCCS_CND_E-49_Y-2040')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_ENG_NGASCCS_CND_E-50_Y-2050')=6.38631E-07;
$ifi %CCS%==yes IM_Resource_prod_elec('GNR_ST_NGASCCS_CND_E-47_LS-400-MW_Y-2020')=6.38631E-07;

*CHP
*GNR_GT_NGASCCS_BP_E-37_SS-5-MW_Y-2020
*GNR_GT_NGASCCS_BP_E-39_SS-5-MW_Y-2030
*GNR_GT_NGASCCS_BP_E-40_SS-5-MW_Y-2040
*GNR_GT_NGASCCS_BP_E-40_SS-5-MW_Y-2050
*GNR_GT_NGASCCS_BP_E-42_LS-40-MW_Y-2020
*GNR_GT_NGASCCS_BP_E-43_LS-40-MW_Y-2030
*GNR_GT_NGASCCS_BP_E-44_LS-40-MW_Y-2040
*GNR_GT_NGASCCS_BP_E-44_LS-40-MW_Y-2050
*GNR_ENG_NGASCCS_BP_E-47_Y-2020
*GNR_ENG_NGASCCS_BP_E-48_Y-2030
*GNR_ENG_NGASCCS_BP_E-49_Y-2040
*GNR_ENG_NGASCCS_BP_E-50_Y-2050
*GNR_ST_NGASCCS_BP_E-7_MS-15-MW_Y-2020
*GNR_ST_NGASCCS_EXT_E-47_LS-400-MW_Y-2020

*heat only
*GNR_BO_NGASCCS_E-105_MS-5-MW_Y-2020
*GNR_BO_NGASCCS_E-105_MS-5-MW_Y-2030
*GNR_BO_NGASCCS_E-105_MS-5-MW_Y-2040
*GNR_BO_NGASCCS_E-105_MS-5-MW_Y-2050
*GNR_IND-BO_NGASCCS_E-93_MS-20-MW_Y-2020
*GNR_IND-BO_NGASCCS_E-93_MS-20-MW_Y-2030
*GNR_IND-BO_NGASCCS_E-93_MS-20-MW_Y-2040
*GNR_IND-BO_NGASCCS_E-93_MS-20-MW_Y-2050
*GNR_IND-DF_NGASCCS_E-100_MS-3-MW_Y-2020
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_CND_E-59_LS-100-MW_Y-2020')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_BP_E-51_SS-10-MW_Y-2020')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_BP_E-53_SS-10-MW_Y-2030')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_BP_E-54_SS-10-MW_Y-2040')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_BP_E-55_SS-10-MW_Y-2050')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_EXT_E-59_LS-100-MW_Y-2020')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_EXT_E-61_LS-100-MW_Y-2030')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_EXT_E-62_LS-100-MW_Y-2040')=0.048;
*$ifi %CCS%==yes IM_CO2_prod_elec('GNR_CC_NGASCCS_EXT_E-63_LS-100-MW_Y-2050')=0.048;





***MAGIC FUEL***
IM_CO2_prod_elec('MAGICG')=EPS;
IM_CO2_constr('MAGICG')=EPS;

IM_Ozone_depletion_constr('MAGICG')=EPS;
IM_Ozone_depletion_prod_elec('MAGICG')=EPS;

IM_Acidification_constr('MAGICG')=EPS;
IM_Acidification_prod_elec('MAGICG')=EPS;

IM_Ecotoxicity_freshwater_constr('MAGICG')=EPS;
IM_Ecotoxicity_freshwater_prod_elec('MAGICG')=EPS;

IM_Eutrophication_freshwater_constr('MAGICG')=EPS;
IM_Eutrophication_freshwater_prod_elec('MAGICG')=EPS;

IM_LU_constr('MAGICG')=EPS;
IM_LU_prod_elec('MAGICG')=EPS;

IM_PM_constr('MAGICG')=EPS;
IM_PM_prod_elec('MAGICG')=EPS;

IM_WU_constr('MAGICG')=EPS;
IM_WU_prod_elec('MAGICG')=EPS;

IM_Resource_constr('MAGICG')=EPS;
IM_Resource_prod_elec('MAGICG')=EPS;

IM_CO2_prod_elec('MAGICGH')=EPS;
IM_CO2_constr('MAGICGH')=EPS;

IM_Ozone_depletion_constr('MAGICGH')=EPS;
IM_Ozone_depletion_prod_elec('MAGICGH')=EPS;

IM_Acidification_constr('MAGICGH')=EPS;
IM_Acidification_prod_elec('MAGICGH')=EPS;

IM_Ecotoxicity_freshwater_constr('MAGICGH')=EPS;
IM_Ecotoxicity_freshwater_prod_elec('MAGICGH')=EPS;

IM_Eutrophication_freshwater_constr('MAGICGH')=EPS;
IM_Eutrophication_freshwater_prod_elec('MAGICGH')=EPS;

IM_LU_constr('MAGICGH')=EPS;
IM_LU_prod_elec('MAGICGH')=EPS;

IM_PM_constr('MAGICGH')=EPS;
IM_PM_prod_elec('MAGICGH')=EPS;

IM_WU_constr('MAGICGH')=EPS;
IM_WU_prod_elec('MAGICGH')=EPS;

IM_Resource_constr('MAGICGH')=EPS;
IM_Resource_prod_elec('MAGICGH')=EPS;


***PV rooftop*** 2030 2040 2050

*IM_CO2_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =2.20E+06;
*IM_CO2_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =5.76E-06;
*IM_Ozone_depletion_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =2.76E-01;
*IM_Ozone_depletion_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =3.79E-13;
*IM_Acidification_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =1.71E+04;
*IM_Acidification_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =4.56E-08;
*IM_Ecotoxicity_freshwater_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =1.05E+08;
*IM_Ecotoxicity_freshwater_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =0.001694352;
*IM_Eutrophication_freshwater_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =1.37E+03;
*IM_Eutrophication_freshwater_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =8.63E-09;
*IM_LU_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =1.15E+07;
*IM_LU_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =3.30E-05;
*IM_PM_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =1.51E-01;
*IM_WU_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =2.20E+06;
*IM_WU_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =2.94E-05;
*IM_Resource_constr('GNR_PV_SUN_SS-6-KW_Y-2050') =2.12E+02;
*IM_Resource_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2050') =5.08E-11;

*IM_CO2_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =2.20E+06;
*IM_Ozone_depletion_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =2.76E-01;
*IM_Ozone_depletion_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =3.79E-13;
*IM_Acidification_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =1.71E+04;
*IM_Acidification_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =4.56E-08;
*IM_Ecotoxicity_freshwater_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =1.05E+08;
*IM_Ecotoxicity_freshwater_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =0.001694352;
*IM_Eutrophication_freshwater_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =1.37E+03;
*IM_Eutrophication_freshwater_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =8.63E-09;
*IM_LU_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =1.15E+07;
*IM_LU_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =3.30E-05;
*IM_PM_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =1.51E-01;
*IM_PM_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =6.00E-13;
*IM_WU_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =2.20E+06;
*IM_WU_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =2.94E-05;
*IM_Resource_constr('GNR_PV_SUN_SS-6-KW_Y-2030') =2.12E+02;
*IM_Resource_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2030') =5.08E-11;

*IM_CO2_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =2.20E+06;
*IM_CO2_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =5.76E-06;
*IM_Ozone_depletion_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =2.76E-01;
*IM_Ozone_depletion_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =3.79E-13;
*IM_Acidification_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =1.71E+04;
*IM_Acidification_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =4.56E-08;
*IM_Ecotoxicity_freshwater_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =1.05E+08;
*IM_Ecotoxicity_freshwater_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =0.001694352;
*IM_Eutrophication_freshwater_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =1.37E+03;
*IM_Eutrophication_freshwater_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =8.63E-09;
*IM_LU_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =1.15E+07;
*IM_LU_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =3.30E-05;
*IM_PM_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =1.51E-01;
*IM_PM_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =6.00E-13;
*IM_WU_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =2.20E+06;
*IM_WU_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =2.94E-05;
*IM_Resource_constr('GNR_PV_SUN_SS-6-KW_Y-2040') =2.12E+02;
*IM_Resource_prod_elec('GNR_PV_SUN_SS-6-KW_Y-2040') =5.08E-11;







