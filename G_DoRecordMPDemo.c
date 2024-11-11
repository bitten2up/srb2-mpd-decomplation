/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
// most of the globals starting with _ were edited by bitten
void G_DoRecordMPDemo(void)

{
  undefined2 *_Source;
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined4 local_414;
  undefined *local_410 [64];
  undefined4 local_310;
  undefined auStack_30c [256];
  undefined4 local_20c [4];
  undefined2 uStack_1fc;
  undefined auStack_1fa [494];
  
  _Source = &srb2home; // tf????
  if (_usehome == 0) {
    _Source = (undefined2 *)&srb2path;
  }
  strcpy((char *)local_20c,(char *)_Source);
  sVar1 = strlen((char *)local_20c);
  mpdemoversion = 9;
  local_414 = 0;
  // this is some kind of struct
  *(undefined2 *)((int)&uStack_1fc + sVar1) = 0x5c6e;
  *(undefined4 *)((int)local_20c + sVar1) = 0x64706d5c;
  *(undefined4 *)((int)local_20c + sVar1 + 4) = 0x2e32765c;
  *(undefined4 *)((int)local_20c + sVar1 + 8) = 0x30312e32;
  *(undefined4 *)((int)local_20c + sVar1 + 0xc) = 0x69616d5c;
  *(undefined *)((int)&uStack_1fc + sVar1 + 2) = 0;
  ppuVar4 = local_410;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined *)0x0;
    ppuVar4 = ppuVar4 + 1;
  }
  pcVar2 = (char *)Newsnapshotfile(local_20c,&DAT_00762c5f);
  if (pcVar2 == (char *)0x0) {
    local_414 = 0x2e74756f;
    local_410[0] = &LAB_0064706d;
  }
  else {
    strncpy((char *)&local_414,pcVar2,0x104);
  }
  mpdsave = 1;
  SV_SaveNetGame(0,0);
  mpdsave = 0;
  strncpy((char *)&local_310,(char *)&local_414,0x104);
  FIL_StripExtension(&local_310);
  sVar1 = strlen((char *)&local_310);
  // another struct
  *(undefined4 *)((int)&local_310 + sVar1) = 0x64706d2e;
  auStack_30c[sVar1] = 0;
  if (((char)local_310 != '\0') && (_mpdstream == (FILE *)0x0)) {
    pcVar2 = (char *)va("%s\\mpd\\v2.2.10\\main\\%s",&srb2home,&local_310);
    mpdstream = fopen(pcVar2,"wb");
  }
  FIL_StripExtension(&local_414);
  G_RecordMPDemo(&local_414);
  G_BeginMPRecording();
  return;
}
