/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
// most of the globals starting with _ were edited by bitten, your welcome

// raw output without structs
void _G_BeginMPRecording(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte bVar8;
  tm *ptVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  char *pcVar12;
  size_t sVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  byte bVar19;
  short *psVar20;
  short *psVar21;
  int iVar22;
  short sVar23;
  int iVar24;
  time_t tVar25;
  char *pcStack_118;
  undefined4 *puStack_114;
  undefined4 uStack_108;
  undefined uStack_101;
  undefined4 auStack_100 [59];
  undefined4 uStack_14;
  
  CONS_Printf("Started MP recording...\n");
  iVar22 = demobuffer;
  demotic = 0;
  demo_p = (undefined8 *)demobuffer;
  demostart_p = demobuffer;
  demoflags = '\0';
  if (multiplayer == 0) {
    demoflags = modeattacking * '\x02' + '\x01';
  }
  (*(code *)M_Memcpy)(demobuffer,&DAT_00762c4f,0xc);
  bVar8 = ultimatemode;
  iVar24 = multiplayer;
  *(char *)((int)demo_p + 0xc) = (char)VERSION;
  uVar11 = SUBVERSION;
  *(undefined2 *)((int)_demo_p + 0xe) = 9;
  *(char *)((int)_demo_p + 0xd) = (char)uVar11;
  bVar19 = bVar8 | 0x1e;
  if (iVar24 != 0) {
    bVar19 = bVar8 | 0xe;
  }
  *(byte *)(demo_p + 2) = bVar19;
  demo_p = (undefined8 *)((int)demo_p + 0x11);
  tVar25 = time((time_t *)0x0);
  uStack_108 = (undefined4)tVar25;
  ptVar9 = localtime((time_t *)&uStack_108);
  iVar24 = ptVar9->tm_year;
  iVar2 = ptVar9->tm_mday;
  iVar3 = ptVar9->tm_hour;
  iVar4 = ptVar9->tm_mon;
  demotic_p = demo_p + 3;
  // who tf knows what a concat44 is... im sure you probally could figure out which macro this is by looking a vinalla functions
  demo_p[2] = CONCAT44(ptVar9->tm_sec,ptVar9->tm_min);
  *demo_p = CONCAT44(iVar4 + 1,iVar24 + 0x76c);
  demo_p[1] = CONCAT44(iVar3,iVar2);
  puVar15 = (undefined4 *)((int)demo_p + 0x1c);
  if (server == 0) {
    iVar24 = 0;
    do {
      pcVar12 = &curservername + iVar24;
      puVar10 = (undefined4 *)((int)puVar15 + 1);
      if (*pcVar12 == '\0') goto LAB_00477171;
      iVar24 = iVar24 + 1;
      *(char *)puVar15 = *pcVar12;
      puVar15 = puVar10;
    } while (iVar24 != 0x20);
  }
  else {
    do {
      puVar10 = (undefined4 *)((int)puVar15 + 1);
      cVar1 = *(char *)((int)puVar15 + (-0x1c - (int)demo_p) + DAT_0073a578);
      if (cVar1 == '\0') goto LAB_00477171;
      *(char *)puVar15 = cVar1;
      puVar15 = puVar10;
    } while ((undefined4 *)((int)_demo_p + 0x3c) != puVar10);
  }
LAB_00477174:
  cVar1 = demoflags;
  uVar5 = gamemap;
  if ((bVar19 & 0x10) == 0) {
    *(undefined2 *)puVar10 = gamemap;
    puVar14 = (undefined8 *)((int)puVar10 + 2);
  }
  else {
    puVar10[1] = 0;
    *(undefined2 *)(puVar10 + 2) = 0;
    *(char *)((int)puVar10 + 0x1a) = cVar1;
    *(undefined2 *)((int)puVar10 + 0x2b) = uVar5;
    *(undefined (*) [16])((int)puVar10 + 10) = (undefined  [16])0x0;
    demo_p = (undefined8 *)((int)puVar10 + 0x2d);
    demotime_p = puVar10;
    *puVar10 = 0;
    (*(code *)M_Memcpy)(demo_p,&mapmd5,0x10);
    puVar14 = demo_p + 2;
  }
  *(short *)puVar14 = gametype;
  psVar21 = (short *)((int)puVar14 + 2);
  do {
    psVar20 = psVar21;
    psVar21 = (short *)((int)psVar20 + 1);
    if (*(char *)((int)psVar20 + (int)((&Gametype_Names)[gametype] + (-2 - (int)puVar14))) == '\0'
       ) {
      *(char *)psVar20 = '\0';
      break;
    }
    *(char *)psVar20 =
         *(char *)((int)psVar20 + (int)((&Gametype_Names)[gametype] + (-2 - (int)puVar14)));
  } while ((short *)((int)puVar14 + 0x1a) != psVar21);
  *(char *)psVar21 = (char)consoleplayer;
  *(char *)(psVar20 + 1) = (char)multiplayer;
  uVar7 = uRam009ec80c;
  uVar6 = DAT_009ec808;
  uVar11 = DAT_009ec804;
  if ((char *)((int)psVar20 + -0x9ec801) < (char *)0x9) {
    // some kind of itterator, probally something like
    // for (int i = 0; i != 0x20; i++)
    iVar24 = 0;
    do {
      *(undefined4 *)((int)psVar20 + iVar24 * 4 + 3) = (&adminplayers)[iVar24];
      iVar24 = iVar24 + 1;
    } while (iVar24 != 0x20);
  }
  else {
    // struct
    *(undefined4 *)((int)psVar20 + 3) = adminplayers;
    *(undefined4 *)((int)psVar20 + 7) = uVar11;
    *(undefined4 *)((int)psVar20 + 0xb) = uVar6;
    *(undefined4 *)((int)psVar20 + 0xf) = uVar7;
    uVar7 = uRam009ec81c;
    uVar6 = uRam009ec818;
    uVar11 = uRam009ec814;
    *(undefined4 *)((int)psVar20 + 0x13) = _DAT_009ec810;
    *(undefined4 *)((int)psVar20 + 0x17) = uVar11;
    *(undefined4 *)((int)psVar20 + 0x1b) = uVar6;
    *(undefined4 *)((int)psVar20 + 0x1f) = uVar7;
    uVar7 = uRam009ec82c;
    uVar6 = uRam009ec828;
    uVar11 = uRam009ec824;
    *(undefined4 *)((int)psVar20 + 0x23) = _DAT_009ec820;
    *(undefined4 *)((int)psVar20 + 0x27) = uVar11;
    *(undefined4 *)((int)psVar20 + 0x2b) = uVar6;
    *(undefined4 *)((int)psVar20 + 0x2f) = uVar7;
    uVar7 = uRam009ec83c;
    uVar6 = uRam009ec838;
    uVar11 = uRam009ec834;
    *(undefined4 *)((int)psVar20 + 0x33) = _DAT_009ec830;
    *(undefined4 *)((int)psVar20 + 0x37) = uVar11;
    *(undefined4 *)((int)psVar20 + 0x3b) = uVar6;
    *(undefined4 *)((int)psVar20 + 0x3f) = uVar7;
    uVar7 = uRam009ec84c;
    uVar6 = uRam009ec848;
    uVar11 = uRam009ec844;
    *(undefined4 *)((int)psVar20 + 0x43) = _DAT_009ec840;
    *(undefined4 *)((int)psVar20 + 0x47) = uVar11;
    *(undefined4 *)((int)psVar20 + 0x4b) = uVar6;
    *(undefined4 *)((int)psVar20 + 0x4f) = uVar7;
    uVar7 = uRam009ec85c;
    uVar6 = uRam009ec858;
    uVar11 = uRam009ec854;
    *(undefined4 *)((int)psVar20 + 0x53) = _DAT_009ec850;
    *(undefined4 *)((int)psVar20 + 0x57) = uVar11;
    *(undefined4 *)((int)psVar20 + 0x5b) = uVar6;
    *(undefined4 *)((int)psVar20 + 0x5f) = uVar7;
    uVar7 = uRam009ec86c;
    uVar6 = uRam009ec868;
    uVar11 = uRam009ec864;
    *(undefined4 *)((int)psVar20 + 99) = _DAT_009ec860;
    *(undefined4 *)((int)psVar20 + 0x67) = uVar11;
    *(undefined4 *)((int)psVar20 + 0x6b) = uVar6;
    *(undefined4 *)((int)psVar20 + 0x6f) = uVar7;
    uVar7 = DAT_009ec87c;
    uVar6 = uRam009ec878;
    uVar11 = uRam009ec874;
    *(undefined4 *)((int)psVar20 + 0x73) = _DAT_009ec870;
    *(undefined4 *)((int)psVar20 + 0x77) = uVar11;
    *(undefined4 *)((int)psVar20 + 0x7b) = uVar6;
    *(undefined4 *)((int)psVar20 + 0x7f) = uVar7;
  }
  demo_p = (undefined8 *)((int)psVar20 + 0x83);
  iVar24 = 0;
  uVar11 = P_GetInitSeed();
  pcStack_118 = &player_names;
  *(undefined4 *)((int)psVar20 + 0x83) = uVar11;
  puStack_114 = &players;
  puVar14 = (undefined8 *)((int)psVar20 + 0x87);
  do {
    puVar17 = (undefined8 *)((int)puVar14 + 1);
    demo_p = puVar17;
    if ((&_playeringame)[iVar24] == 0) {
      *(char *)puVar14 = '\0';
    }
    else {
      *(char *)puVar14 = '\x01';
      (*(code *)M_Memcpy)(puVar17,puStack_114,0x230);
      puVar17 = (undefined8 *)((int)demo_p + 0x245);
      puVar14 = demo_p + 0x46;
      pcVar12 = pcStack_118;
      do {
        demo_p = (undefined8 *)((int)puVar14 + 1);
        if (*pcVar12 == '\0') {
          *(char *)puVar14 = '\0';
          puVar17 = demo_p;
          break;
        }
        *(char *)puVar14 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        puVar14 = demo_p;
      } while (puVar17 != demo_p);
    }
    iVar24 = iVar24 + 1;
    pcStack_118 = pcStack_118 + 0x16;
    puStack_114 = puStack_114 + 0x8c;
    puVar14 = puVar17;
  } while (iVar24 != 0x20);
  puVar15 = &mpoldcmd;
  for (iVar24 = 0x48; iVar2 = consoleplayer, iVar24 != 0; iVar24 = iVar24 + -1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  if (multiplayer == 0) {
    puVar15 = &oldghost;
    for (iVar24 = 0x4b; uVar16 = 0, iVar24 != 0; iVar24 = iVar24 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    do {
      *(undefined4 *)((int)&_ghostext + uVar16) = 0;
      uVar16 = uVar16 + 4;
    } while (uVar16 < 0x18);
    DAT_009f7c48 = 0x10000;
    DAT_009f7c4c = 0x10000;
    iVar24 = (&players)[iVar2 * 0x8c];
    if (iVar24 != 0) {
      //struct
      DAT_009f7958 = *(undefined4 *)(iVar24 + 0x18);
      DAT_009f7950 = *(undefined8 *)(iVar24 + 0x10);
      DAT_009f7964 = (uint)*(byte *)(iVar24 + 0x27);
      if ((*(byte *)(iVar24 + 0x9c) & 0x20) != 0) {
        ghostext._0_1_ = 8;
      }
    }
  }
  firsttic = 1;
  curlaggedtics = 0;
  startedmprecording = 1;
  I_OutputToStream(iVar22,(int)puVar17 - iVar22,mpdstream);
  puVar14 = demo_p;
  if (multiplayer != 0) {
    iVar22 = 0;
    do {
      if (iVar22 == 0) {
        if (curserveraddress == '\0') {
          iVar24 = 0;
          if (playeringame != 0) goto LAB_00477405;
        }
        else {
          iVar24 = 0;
          // possibally a struct, but its a UINT8 ** in base game so who fucking knows
          *(undefined *)(demo_p + 2) = 0;
          *(undefined4 *)demo_p = 0xfffffffe;
          *(undefined4 *)((int)demo_p + 4) = 0xfffffffd;
          *(undefined4 *)(demo_p + 1) = 0xfffffffb;
          *(undefined4 *)((int)demo_p + 0xc) = 0xfffffff7;
          puVar17 = (undefined8 *)((int)demo_p + 0x11);
          // itterator
          do {
            pcVar12 = &curserveraddress + iVar24;
            demo_p = (undefined8 *)((int)puVar17 + 1);
            if (*pcVar12 == '\0') {
              *(char *)puVar17 = '\0';
              break;
            }
            iVar24 = iVar24 + 1;
            *(char *)puVar17 = *pcVar12;
            puVar17 = demo_p;
          } while (iVar24 != 0x40);
        }
      }
      else {
        iVar24 = iVar22;
        if ((&playeringame)[iVar22] != 0) {
LAB_00477405:
          if ((I_GetNodeAddress != NULL) &&
             (pcVar12 = (char *)(*I_GetNodeAddress)((&playernode)[iVar24]), pcVar12 != NULL
             )) {
            puVar17 = (undefined8 *)((int)demo_p + 0x51);
            *(char *)(demo_p + 2) = (char)iVar22;
            *(undefined4 *)demo_p = 0xfffffffe;
            *(undefined4 *)((int)demo_p + 4) = 0xfffffffd;
            *(undefined4 *)(demo_p + 1) = 0xfffffffb;
            *(undefined4 *)((int)demo_p + 0xc) = 0xfffffff7;
            puVar18 = (undefined8 *)((int)demo_p + 0x11);
            do {
              demo_p = (undefined8 *)((int)puVar18 + 1);
              if (*pcVar12 == '\0') {
                *(undefined *)puVar18 = 0;
                break;
              }
              *(char *)puVar18 = *pcVar12;
              pcVar12 = pcVar12 + 1;
              puVar18 = demo_p;
            } while (puVar17 != demo_p);
          }
          *(char *)(demo_p + 2) = (char)iVar22;
          *(undefined4 *)demo_p = 0xfffffffe;
          *(undefined4 *)((int)demo_p + 4) = 0xfffffffd;
          *(undefined4 *)(demo_p + 1) = 0xfffffffb;
          *(undefined4 *)((int)demo_p + 0xc) = 0xfffffff6;
          *(undefined1 *)((int)demo_p + 0x11) = (&playernode)[iVar24];
          _demo_p = (undefined8 *)((int)demo_p + 0x12);
        }
        if (iVar22 == 0x1f) goto LAB_004774dc;
      }
      iVar22 = iVar22 + 1;
    } while( true );
  }
LAB_0047767d:
  *(undefined *)demo_p = 0xff;
  iVar22 = mpdsavelength;
  puVar17 = (undefined8 *)((int)demo_p + 5);
  if (multiplayer == 0) {
    mpdsavelength = 0;
    *(undefined4 *)((int)demo_p + 1) = 0;
    demo_p = puVar17;
  }
  else {
    *(int *)((int)demo_p + 1) = mpdsavelength;
    demo_p = puVar17;
    if (iVar22 != 0) {
      (*(code *)M_Memcpy)(puVar17,mpdsavebuffer,iVar22);
      free(mpdsavebuffer);
      demo_p = (undefined8 *)(mpdsavelength + (int)demo_p);
      mpdsavelength = 0;
    }
  }
  I_OutputToStream(puVar14,(int)demo_p - (int)puVar14,mpdstream);
  return;
LAB_00477171:
  *(undefined *)puVar15 = 0;
  goto LAB_00477174;
LAB_004774dc:
  if (numwadfiles != 0) {
    iVar22 = 1;
    uVar11 = _va(&DAT_00762c5c,*(undefined4 *)*wadfiles);
    _nameonly(uVar11);
    if (1 < _numwadfiles) {
      sVar23 = 1;
      do {
        pcVar12 = (char *)va(&DAT_00762c5c,*(undefined4 *)wadfiles[iVar22]);
        _nameonly(pcVar12);
        if (((sVar23 != 0) && ((int)(uint)mainwads < iVar22)) &&
           (iVar24 = W_VerifyNMUSlumps(*(undefined4 *)wadfiles[iVar22],0), iVar24 == 0)) {
          _uStack_101 = 0;
          uStack_14 = 0;
          puVar15 = (undefined4 *)(&uStack_101 + 1);
          for (uVar16 = (uint)(&stack0xfffffff0 + -(int)(&uStack_101 + 1)) >> 2; uVar16 != 0;
              uVar16 = uVar16 - 1) {
            *puVar15 = 0;
            puVar15 = puVar15 + 1;
          }
          sVar13 = strlen(pcVar12);
          (*(code *)M_Memcpy)(&uStack_101,pcVar12,sVar13);
          sVar13 = strlen(pcVar12);
          (&uStack_101)[sVar13] = 0;
          *(undefined4 *)demo_p = 0xfffffffe;
          *(undefined4 *)((int)demo_p + 4) = 0xfffffffd;
          *(undefined4 *)(demo_p + 1) = 0xfffffffc;
          *(undefined4 *)((int)demo_p + 0xc) = 0xfffffffc;
          _demo_p = demo_p + 2;
          (*(code *)M_Memcpy)(demo_p,&uStack_101,0xf1);
          demo_p = (undefined8 *)((int)demo_p + 0xf1);
          (*(code *)M_Memcpy)(demo_p,_wadfiles[iVar22] + 0x24,0x10);
          demo_p = demo_p + 2;
        }
        sVar23 = sVar23 + 1;
        iVar22 = (int)sVar23;
      } while (iVar22 < (int)(uint)_numwadfiles);
    }
  }
  goto LAB_0047767d;
}

// anotated ghidra output

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _G_BeginMPRecording(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte bVar8;
  tm *ptVar9;
  undefined4 *puVar10;
  short *psVar11;
  undefined4 uVar12;
  char *pcVar13;
  size_t sVar14;
  undefined4 *puVar15;
  char *pcVar16;
  uint uVar17;
  char *pcVar18;
  byte bVar19;
  astruct *psVar20;
  astruct *paVar20;
  int iVar21;
  short sVar22;
  int iVar23;
  time_t tVar24;
  char *pcStack_118;
  undefined4 *puStack_114;
  undefined4 uStack_108;
  undefined uStack_101;
  undefined4 auStack_100 [59];
  undefined4 uStack_14;
  
  _CONS_Printf("Started MP recording...\n");
  iVar21 = demobuffer;
  demotic = 0;
  demo_p = (char *)demobuffer;
  demostart_p = demobuffer;
  demoflags = '\0';
  if (multiplayer == 0) {
    demoflags = modeattacking * '\x02' + '\x01';
  }
  (*(code *)M_Memcpy)(demobuffer,&DAT_00762c4f,0xc);
  bVar8 = ultimatemode;
  iVar23 = multiplayer;
  demo_p[0xc] = (char)_VERSION;
  uVar12 = _SUBVERSION;
  *(undefined2 *)(demo_p + 0xe) = 9;
  demo_p[0xd] = (char)uVar12;
  bVar19 = bVar8 | 0x1e;
  if (iVar23 != 0) {
    bVar19 = bVar8 | 0xe;
  }
  demo_p[0x10] = bVar19;
  demo_p = demo_p + 0x11;
  tVar24 = time(NULL);
  uStack_108 = (undefined4)tVar24;
  ptVar9 = localtime((time_t *)&uStack_108);
  iVar23 = ptVar9->tm_year;
  iVar2 = ptVar9->tm_mday;
  iVar3 = ptVar9->tm_hour;
  iVar4 = ptVar9->tm_mon;
  _demotic_p = (undefined8 *)(demo_p + 0x18);
  *(ulonglong *)(demo_p + 0x10) = CONCAT44(ptVar9->tm_sec,ptVar9->tm_min);
  *(ulonglong *)demo_p = CONCAT44(iVar4 + 1,iVar23 + 0x76c);
  *(ulonglong *)(demo_p + 8) = CONCAT44(iVar3,iVar2);
  puVar15 = (undefined4 *)(demo_p + 0x1c);
  if (_server == 0) {
    iVar23 = 0;
    do {
      pcVar13 = &curservername + iVar23;
      puVar10 = (undefined4 *)((int)puVar15 + 1);
      if (*pcVar13 == '\0') goto LAB_00477171;
      iVar23 = iVar23 + 1;
      *(char *)puVar15 = *pcVar13;
      puVar15 = puVar10;
    } while (iVar23 != 0x20);
  }
  else {
    do {
      puVar10 = (undefined4 *)((int)puVar15 + 1);
      cVar1 = *(char *)((int)puVar15 + (-0x1c - (int)demo_p) + DAT_0073a578);
      if (cVar1 == '\0') goto LAB_00477171;
      *(char *)puVar15 = cVar1;
      puVar15 = puVar10;
    } while ((undefined4 *)(demo_p + 0x3c) != puVar10);
  }
LAB_00477174:
  cVar1 = demoflags;
  uVar5 = gamemap;
  if ((bVar19 & 0x10) == 0) {
    *(undefined2 *)puVar10 = gamemap;
    psVar11 = (short *)((int)puVar10 + 2);
  }
  else {
    puVar10[1] = 0;
    *(undefined2 *)(puVar10 + 2) = 0;
    *(char *)((int)puVar10 + 0x1a) = cVar1;
    *(undefined2 *)((int)puVar10 + 0x2b) = uVar5;
    *(undefined (*) [16])((int)puVar10 + 10) = (undefined  [16])0x0;
    demo_p = (char *)((int)puVar10 + 0x2d);
    demotime_p = puVar10;
    *puVar10 = 0;
    (*(code *)M_Memcpy)(demo_p,&mapmd5,0x10);
    psVar11 = (short *)(demo_p + 0x10);
  }
  *psVar11 = gametype;
  paVar20 = (astruct *)(psVar11 + 1);
  do {
    psVar20 = paVar20;
    paVar20 = (astruct *)&psVar20->field1_0x1;
    if (((&Gametype_Names)[gametype] + (-2 - (int)psVar11))[(int)&psVar20->field0_0x0] == '\0') {
      psVar20->field0_0x0 = '\0';
      break;
    }
    psVar20->field0_0x0 =
         ((&Gametype_Names)[gametype] + (-2 - (int)psVar11))[(int)&psVar20->field0_0x0];
  } while ((astruct *)(psVar11 + 0xd) != paVar20);
  *(char *)paVar20 = (char)consoleplayer;
  psVar20->field2_0x2 = (char)multiplayer;
  uVar7 = uRam009ec80c;
  uVar6 = DAT_009ec808;
  uVar12 = DAT_009ec804;
  if (&psVar20[-0x11a48].field34_0x7f < (undefined4 *)0x9) {
    iVar23 = 0;
    do {
      (&psVar20->field3_0x3)[iVar23] = (&adminplayers)[iVar23];
      iVar23 = iVar23 + 1;
    } while (iVar23 != 0x20);
  }
  else {
    psVar20->field3_0x3 = adminplayers;
    psVar20->field4_0x7 = uVar12;
    psVar20->field5_0xb = uVar6;
    psVar20->field6_0xf = uVar7;
    uVar7 = uRam009ec81c;
    uVar6 = uRam009ec818;
    uVar12 = uRam009ec814;
    psVar20->field7_0x13 = _DAT_009ec810;
    psVar20->field8_0x17 = uVar12;
    psVar20->field9_0x1b = uVar6;
    psVar20->field10_0x1f = uVar7;
    uVar7 = uRam009ec82c;
    uVar6 = uRam009ec828;
    uVar12 = uRam009ec824;
    psVar20->field11_0x23 = _DAT_009ec820;
    psVar20->field12_0x27 = uVar12;
    psVar20->field13_0x2b = uVar6;
    psVar20->field14_0x2f = uVar7;
    uVar7 = uRam009ec83c;
    uVar6 = uRam009ec838;
    uVar12 = uRam009ec834;
    psVar20->field15_0x33 = _DAT_009ec830;
    psVar20->field16_0x37 = uVar12;
    psVar20->field17_0x3b = uVar6;
    psVar20->field18_0x3f = uVar7;
    uVar7 = uRam009ec84c;
    uVar6 = uRam009ec848;
    uVar12 = uRam009ec844;
    psVar20->field19_0x43 = _DAT_009ec840;
    psVar20->field20_0x47 = uVar12;
    psVar20->field21_0x4b = uVar6;
    psVar20->field22_0x4f = uVar7;
    uVar7 = uRam009ec85c;
    uVar6 = uRam009ec858;
    uVar12 = uRam009ec854;
    psVar20->field23_0x53 = _DAT_009ec850;
    psVar20->field24_0x57 = uVar12;
    psVar20->field25_0x5b = uVar6;
    psVar20->field26_0x5f = uVar7;
    uVar7 = uRam009ec86c;
    uVar6 = uRam009ec868;
    uVar12 = uRam009ec864;
    psVar20->field27_0x63 = _DAT_009ec860;
    psVar20->field28_0x67 = uVar12;
    psVar20->field29_0x6b = uVar6;
    psVar20->field30_0x6f = uVar7;
    uVar7 = DAT_009ec87c;
    uVar6 = uRam009ec878;
    uVar12 = uRam009ec874;
    psVar20->field31_0x73 = _DAT_009ec870;
    psVar20->field32_0x77 = uVar12;
    psVar20->field33_0x7b = uVar6;
    psVar20->field34_0x7f = uVar7;
  }
  demo_p = (char *)&psVar20->field35_0x83;
  iVar23 = 0;
  uVar12 = P_GetInitSeed();
  pcStack_118 = &player_names;
  psVar20->field35_0x83 = uVar12;
  puStack_114 = &players;
  pcVar13 = &psVar20->field36_0x87;
  do {
    pcVar18 = pcVar13 + 1;
    demo_p = pcVar18;
    if ((&playeringame)[iVar23] == 0) {
      *pcVar13 = '\0';
    }
    else {
      *pcVar13 = '\x01';
      (*(code *)M_Memcpy)(pcVar18,puStack_114,0x230);
      pcVar18 = demo_p + 0x245;
      pcVar13 = demo_p + 0x230;
      pcVar16 = pcStack_118;
      do {
        demo_p = pcVar13 + 1;
        if (*pcVar16 == '\0') {
          *pcVar13 = '\0';
          pcVar18 = demo_p;
          break;
        }
        *pcVar13 = *pcVar16;
        pcVar16 = pcVar16 + 1;
        pcVar13 = demo_p;
      } while (pcVar18 != demo_p);
    }
    iVar23 = iVar23 + 1;
    pcStack_118 = pcStack_118 + 0x16;
    puStack_114 = puStack_114 + 0x8c;
    pcVar13 = pcVar18;
  } while (iVar23 != 0x20);
  puVar15 = &mpoldcmd;
  for (iVar23 = 0x48; iVar2 = consoleplayer, iVar23 != 0; iVar23 = iVar23 + -1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  if (multiplayer == 0) {
    puVar15 = &oldghost;
    for (iVar23 = 0x4b; uVar17 = 0, iVar23 != 0; iVar23 = iVar23 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    do {
      *(undefined4 *)((int)&ghostext + uVar17) = 0;
      uVar17 = uVar17 + 4;
    } while (uVar17 < 0x18);
    DAT_009f7c48 = 0x10000;
    DAT_009f7c4c = 0x10000;
    iVar23 = (&players)[iVar2 * 0x8c];
    if (iVar23 != 0) {
      DAT_009f7958 = *(undefined4 *)(iVar23 + 0x18);
      DAT_009f7950 = *(undefined8 *)(iVar23 + 0x10);
      DAT_009f7964 = (uint)*(byte *)(iVar23 + 0x27);
      if ((*(byte *)(iVar23 + 0x9c) & 0x20) != 0) {
        ghostext._0_1_ = 8;
      }
    }
  }
  firsttic = 1;
  curlaggedtics = 0;
  startedmprecording = 1;
  I_OutputToStream(iVar21,(int)pcVar18 - iVar21,mpdstream);
  pcVar13 = demo_p;
  if (multiplayer != 0) {
    iVar21 = 0;
    do {
      if (iVar21 == 0) {
        if (curserveraddress == '\0') {
          iVar23 = 0;
          if (playeringame != 0) goto LAB_00477405;
        }
        else {
          iVar23 = 0;
          demo_p[0x10] = '\0';
          *(undefined4 *)demo_p = 0xfffffffe;
          *(undefined4 *)(demo_p + 4) = 0xfffffffd;
          *(undefined4 *)(demo_p + 8) = 0xfffffffb;
          *(undefined4 *)(demo_p + 0xc) = 0xfffffff7;
          pcVar18 = demo_p + 0x11;
          do {
            pcVar16 = &curserveraddress + iVar23;
            demo_p = pcVar18 + 1;
            if (*pcVar16 == '\0') {
              *pcVar18 = '\0';
              break;
            }
            iVar23 = iVar23 + 1;
            *pcVar18 = *pcVar16;
            pcVar18 = demo_p;
          } while (iVar23 != 0x40);
        }
      }
      else {
        iVar23 = iVar21;
        if ((&playeringame)[iVar21] != 0) {
LAB_00477405:
          if ((I_GetNodeAddress != NULL) &&
             (pcVar18 = (char *)(*I_GetNodeAddress)((&_playernode)[iVar23]), pcVar18 != NULL)) {
            puVar15 = (undefined4 *)(demo_p + 0x51);
            demo_p[0x10] = (char)iVar21;
            *(undefined4 *)demo_p = 0xfffffffe;
            *(undefined4 *)(demo_p + 4) = 0xfffffffd;
            *(undefined4 *)(demo_p + 8) = 0xfffffffb;
            *(undefined4 *)(demo_p + 0xc) = 0xfffffff7;
            puVar10 = (undefined4 *)(demo_p + 0x11);
            do {
              demo_p = (char *)((int)puVar10 + 1);
              if (*pcVar18 == '\0') {
                *(undefined *)puVar10 = 0;
                break;
              }
              *(char *)puVar10 = *pcVar18;
              pcVar18 = pcVar18 + 1;
              puVar10 = (undefined4 *)demo_p;
            } while (puVar15 != (undefined4 *)demo_p);
          }
          *(char *)((int)demo_p + 0x10) = (char)iVar21;
          *(undefined4 *)demo_p = 0xfffffffe;
          *(undefined4 *)((int)demo_p + 4) = 0xfffffffd;
          *(undefined4 *)((int)demo_p + 8) = 0xfffffffb;
          *(undefined4 *)((int)demo_p + 0xc) = 0xfffffff6;
          *(undefined1 *)((int)demo_p + 0x11) = (&_playernode)[iVar23];
          demo_p = (char *)((int)demo_p + 0x12);
        }
        if (iVar21 == 0x1f) goto LAB_004774dc;
      }
      iVar21 = iVar21 + 1;
    } while( true );
  }
LAB_0047767d:
  *demo_p = -1;
  iVar21 = mpdsavelength;
  pcVar18 = demo_p + 5;
  if (multiplayer == 0) {
    mpdsavelength = 0;
    *(undefined4 *)(demo_p + 1) = 0;
    demo_p = pcVar18;
  }
  else {
    *(int *)(demo_p + 1) = mpdsavelength;
    demo_p = pcVar18;
    if (iVar21 != 0) {
      (*(code *)M_Memcpy)(pcVar18,mpdsavebuffer,iVar21);
      free(mpdsavebuffer);
      demo_p = demo_p + mpdsavelength;
      mpdsavelength = 0;
    }
  }
  I_OutputToStream(pcVar13,(int)demo_p - (int)pcVar13,mpdstream);
  return;
LAB_00477171:
  *(undefined *)puVar15 = 0;
  goto LAB_00477174;
LAB_004774dc:
  if (numwadfiles != 0) {
    iVar21 = 1;
    uVar12 = va(&DAT_00762c5c,*(undefined4 *)*wadfiles);
    _nameonly(uVar12);
    if (1 < numwadfiles) {
      sVar22 = 1;
      do {
        pcVar18 = (char *)va(&DAT_00762c5c,*(undefined4 *)wadfiles[iVar21]);
        _nameonly(pcVar18);
        if (((sVar22 != 0) && ((int)(uint)mainwads < iVar21)) &&
           (iVar23 = _W_VerifyNMUSlumps(*(undefined4 *)wadfiles[iVar21],0), iVar23 == 0)) {
          _uStack_101 = 0;
          uStack_14 = 0;
          puVar15 = (undefined4 *)(&uStack_101 + 1);
          for (uVar17 = (uint)(&stack0xfffffff0 + -(int)(&uStack_101 + 1)) >> 2; uVar17 != 0;
              uVar17 = uVar17 - 1) {
            *puVar15 = 0;
            puVar15 = puVar15 + 1;
          }
          sVar14 = strlen(pcVar18);
          (*(code *)M_Memcpy)(&uStack_101,pcVar18,sVar14);
          sVar14 = strlen(pcVar18);
          (&uStack_101)[sVar14] = 0;
          *(undefined4 *)demo_p = 0xfffffffe;
          *(undefined4 *)(demo_p + 4) = 0xfffffffd;
          *(undefined4 *)(demo_p + 8) = 0xfffffffc;
          *(undefined4 *)(demo_p + 0xc) = 0xfffffffc;
          demo_p = demo_p + 0x10;
          (*(code *)M_Memcpy)(demo_p,&uStack_101,0xf1);
          demo_p = demo_p + 0xf1;
          (*(code *)M_Memcpy)(demo_p,wadfiles[iVar21] + 0x24,0x10);
          demo_p = demo_p + 0x10;
        }
        sVar22 = sVar22 + 1;
        iVar21 = (int)sVar22;
      } while (iVar21 < (int)(uint)numwadfiles);
    }
  }
  goto LAB_0047767d;
}
