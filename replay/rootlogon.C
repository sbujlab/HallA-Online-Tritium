//////////////////////////////////////////////////////////////////////////
//                                                                          
// rootlogon.C                                                            
//                                                                          
// Load Lib, paths and possible scripts to the analyzer upon start
//                                                                          
//////////////////////////////////////////////////////////////////////////
//	
// Author : Jin Huang <mailto:jinhuang@jlab.org>    Mar 2008
//          Chao Gu         Update for g2p use      Mar 2012
//          Kalyan Allada   Update for GMp expt.    Dec 2013
//	    Florian Hauenstein   Update for Tritum expt.    Feb 2017
//          Tyler Hague     1.6 compatability update Sep 2017
//
//////////////////////////////////////////////////////////////////////////

{
  //Used for setting paths. %s is necessary so that it can be used to Form the paths.
  //This allows changing the directory in only one place for ease of portability.
  static const char* replay_dir_prefix = "./%s";
  TString Arch(gSystem->GetBuildArch());
  TString Arch32("linux");
  TString Arch64("linuxx8664gcc");
  if(Arch==Arch32){
    printf("\nrootlogon.C: Loading Replay Core Library..."); 
  //  gSystem->Load(Form(replay_dir_prefix,"old/ReplayCore_C.so"));
  }

  else if(Arch==Arch64){
    printf("\nrootlogon.C: Loading Replay Core Library..."); 
    gSystem->Load(Form(replay_dir_prefix,"ReplayCore64_C.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tritium_Xscin/libTritium_Xscin.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriFadcScin/libTriFadcScin.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriFadcXscin/libTriFadcXscin.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriFadcCherenkov/libTriFadcCherenkov.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriFadcShower/libTriFadcShower.so"));
    gSystem->Load(Form("./libraries/Tritium_HRS/libTritium_HRS.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tritium_TSScaler/libTritium_TSScaler.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tritium_Evt100/libTritium_THaScaler100EvtHandler.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tritium_Beam_Eloss/libTritium_Beam_Eloss.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tritium_Track_Eloss/libTritium_Track_Eloss.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriScalerEvtHandler/libTriScaler.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriFadcRasteredBeam/libTriFadcRasteredBeam.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriFadcUnRasteredBeam/libTriFadcUnRasteredBeam.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriVDCeff/libTriVDCeff.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriOldTrack/libTriOldTrack.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriBCM/libTriBCM.so"));
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriF1VETROC/libVETROCF1tdc_tritium.so")); 
    gSystem->Load(Form(replay_dir_prefix,"libraries/TriV1495/libV1495_tritium.so")); 
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tri_ElossCorrection/libTri_ElossCorrection.so")); 
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tri_Beam_Eloss/libTri_Beam_Eloss.so")); 
    gSystem->Load(Form(replay_dir_prefix,"libraries/Tri_Track_Eloss/libTri_Track_Eloss.so")); 

  }

    //Load more libs here, if necessary. 
    //Make sure it's in path of $LD_LIBRARY_PATH

    printf("\nrootlogon.C: Adding include directories...");

    gSystem->AddIncludePath("-I$ANALYZER");
    gInterpreter->AddIncludePath("$ANALYZER/");

    gSystem->AddIncludePath("-I$ANALYZER/src");
    gInterpreter->AddIncludePath("$ANALYZER/src/");

    gSystem->AddIncludePath("-I$ANALYZER/hana_decode");
    gInterpreter->AddIncludePath("$ANALYZER/hana_decode/");

    gSystem->AddIncludePath("-I$ANALYZER/hana_scaler");
    gInterpreter->AddIncludePath("$ANALYZER/hana_scaler/");

    printf("\nrootlogon.C: Done!\n\n");
}
