ifdef RAX
	.code
		extern OriginalFuncs_dwmapi:QWORD
		DwmpDxGetWindowSharedSurface proc
			jmp QWORD ptr OriginalFuncs_dwmapi[0 * 8]
		DwmpDxGetWindowSharedSurface endp
		DwmpDxUpdateWindowSharedSurface proc
			jmp QWORD ptr OriginalFuncs_dwmapi[1 * 8]
		DwmpDxUpdateWindowSharedSurface endp
		DwmEnableComposition proc
			jmp QWORD ptr OriginalFuncs_dwmapi[2 * 8]
		DwmEnableComposition endp
		dwmapiExportByOrdinal0 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[3 * 8]
		dwmapiExportByOrdinal0 endp
		dwmapiExportByOrdinal1 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[4 * 8]
		dwmapiExportByOrdinal1 endp
		dwmapiExportByOrdinal2 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[5 * 8]
		dwmapiExportByOrdinal2 endp
		dwmapiExportByOrdinal3 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[6 * 8]
		dwmapiExportByOrdinal3 endp
		dwmapiExportByOrdinal4 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[7 * 8]
		dwmapiExportByOrdinal4 endp
		dwmapiExportByOrdinal5 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[8 * 8]
		dwmapiExportByOrdinal5 endp
		dwmapiExportByOrdinal6 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[9 * 8]
		dwmapiExportByOrdinal6 endp
		dwmapiExportByOrdinal7 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[10 * 8]
		dwmapiExportByOrdinal7 endp
		DllCanUnloadNow proc
			jmp QWORD ptr OriginalFuncs_dwmapi[11 * 8]
		DllCanUnloadNow endp
		dwmapiExportByOrdinal8 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[12 * 8]
		dwmapiExportByOrdinal8 endp
		dwmapiExportByOrdinal9 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[13 * 8]
		dwmapiExportByOrdinal9 endp
		dwmapiExportByOrdinal10 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[14 * 8]
		dwmapiExportByOrdinal10 endp
		DllGetClassObject proc
			jmp QWORD ptr OriginalFuncs_dwmapi[15 * 8]
		DllGetClassObject endp
		DwmAttachMilContent proc
			jmp QWORD ptr OriginalFuncs_dwmapi[16 * 8]
		DwmAttachMilContent endp
		DwmDefWindowProc proc
			jmp QWORD ptr OriginalFuncs_dwmapi[17 * 8]
		DwmDefWindowProc endp
		DwmDetachMilContent proc
			jmp QWORD ptr OriginalFuncs_dwmapi[18 * 8]
		DwmDetachMilContent endp
		DwmEnableBlurBehindWindow proc
			jmp QWORD ptr OriginalFuncs_dwmapi[19 * 8]
		DwmEnableBlurBehindWindow endp
		DwmEnableMMCSS proc
			jmp QWORD ptr OriginalFuncs_dwmapi[20 * 8]
		DwmEnableMMCSS endp
		DwmExtendFrameIntoClientArea proc
			jmp QWORD ptr OriginalFuncs_dwmapi[21 * 8]
		DwmExtendFrameIntoClientArea endp
		DwmFlush proc
			jmp QWORD ptr OriginalFuncs_dwmapi[22 * 8]
		DwmFlush endp
		DwmGetColorizationColor proc
			jmp QWORD ptr OriginalFuncs_dwmapi[23 * 8]
		DwmGetColorizationColor endp
		dwmapiExportByOrdinal11 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[24 * 8]
		dwmapiExportByOrdinal11 endp
		DwmGetCompositionTimingInfo proc
			jmp QWORD ptr OriginalFuncs_dwmapi[25 * 8]
		DwmGetCompositionTimingInfo endp
		DwmGetGraphicsStreamClient proc
			jmp QWORD ptr OriginalFuncs_dwmapi[26 * 8]
		DwmGetGraphicsStreamClient endp
		DwmpGetColorizationParameters proc
			jmp QWORD ptr OriginalFuncs_dwmapi[27 * 8]
		DwmpGetColorizationParameters endp
		DwmpDxgiIsThreadDesktopComposited proc
			jmp QWORD ptr OriginalFuncs_dwmapi[28 * 8]
		DwmpDxgiIsThreadDesktopComposited endp
		DwmGetGraphicsStreamTransformHint proc
			jmp QWORD ptr OriginalFuncs_dwmapi[29 * 8]
		DwmGetGraphicsStreamTransformHint endp
		DwmGetTransportAttributes proc
			jmp QWORD ptr OriginalFuncs_dwmapi[30 * 8]
		DwmGetTransportAttributes endp
		DwmpSetColorizationParameters proc
			jmp QWORD ptr OriginalFuncs_dwmapi[31 * 8]
		DwmpSetColorizationParameters endp
		dwmapiExportByOrdinal12 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[32 * 8]
		dwmapiExportByOrdinal12 endp
		DwmGetUnmetTabRequirements proc
			jmp QWORD ptr OriginalFuncs_dwmapi[33 * 8]
		DwmGetUnmetTabRequirements endp
		DwmGetWindowAttribute proc
			jmp QWORD ptr OriginalFuncs_dwmapi[34 * 8]
		DwmGetWindowAttribute endp
		DwmpRenderFlick proc
			jmp QWORD ptr OriginalFuncs_dwmapi[35 * 8]
		DwmpRenderFlick endp
		DwmpAllocateSecurityDescriptor proc
			jmp QWORD ptr OriginalFuncs_dwmapi[36 * 8]
		DwmpAllocateSecurityDescriptor endp
		DwmpFreeSecurityDescriptor proc
			jmp QWORD ptr OriginalFuncs_dwmapi[37 * 8]
		DwmpFreeSecurityDescriptor endp
		dwmapiExportByOrdinal13 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[38 * 8]
		dwmapiExportByOrdinal13 endp
		dwmapiExportByOrdinal14 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[39 * 8]
		dwmapiExportByOrdinal14 endp
		dwmapiExportByOrdinal15 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[40 * 8]
		dwmapiExportByOrdinal15 endp
		dwmapiExportByOrdinal16 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[41 * 8]
		dwmapiExportByOrdinal16 endp
		dwmapiExportByOrdinal17 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[42 * 8]
		dwmapiExportByOrdinal17 endp
		DwmpEnableDDASupport proc
			jmp QWORD ptr OriginalFuncs_dwmapi[43 * 8]
		DwmpEnableDDASupport endp
		dwmapiExportByOrdinal18 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[44 * 8]
		dwmapiExportByOrdinal18 endp
		dwmapiExportByOrdinal19 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[45 * 8]
		dwmapiExportByOrdinal19 endp
		dwmapiExportByOrdinal20 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[46 * 8]
		dwmapiExportByOrdinal20 endp
		dwmapiExportByOrdinal21 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[47 * 8]
		dwmapiExportByOrdinal21 endp
		dwmapiExportByOrdinal22 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[48 * 8]
		dwmapiExportByOrdinal22 endp
		DwmInvalidateIconicBitmaps proc
			jmp QWORD ptr OriginalFuncs_dwmapi[49 * 8]
		DwmInvalidateIconicBitmaps endp
		dwmapiExportByOrdinal23 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[50 * 8]
		dwmapiExportByOrdinal23 endp
		dwmapiExportByOrdinal24 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[51 * 8]
		dwmapiExportByOrdinal24 endp
		dwmapiExportByOrdinal25 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[52 * 8]
		dwmapiExportByOrdinal25 endp
		dwmapiExportByOrdinal26 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[53 * 8]
		dwmapiExportByOrdinal26 endp
		dwmapiExportByOrdinal27 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[54 * 8]
		dwmapiExportByOrdinal27 endp
		dwmapiExportByOrdinal28 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[55 * 8]
		dwmapiExportByOrdinal28 endp
		DwmTetherTextContact proc
			jmp QWORD ptr OriginalFuncs_dwmapi[56 * 8]
		DwmTetherTextContact endp
		dwmapiExportByOrdinal29 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[57 * 8]
		dwmapiExportByOrdinal29 endp
		dwmapiExportByOrdinal30 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[58 * 8]
		dwmapiExportByOrdinal30 endp
		dwmapiExportByOrdinal31 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[59 * 8]
		dwmapiExportByOrdinal31 endp
		dwmapiExportByOrdinal32 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[60 * 8]
		dwmapiExportByOrdinal32 endp
		dwmapiExportByOrdinal33 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[61 * 8]
		dwmapiExportByOrdinal33 endp
		dwmapiExportByOrdinal34 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[62 * 8]
		dwmapiExportByOrdinal34 endp
		dwmapiExportByOrdinal35 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[63 * 8]
		dwmapiExportByOrdinal35 endp
		dwmapiExportByOrdinal36 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[64 * 8]
		dwmapiExportByOrdinal36 endp
		dwmapiExportByOrdinal37 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[65 * 8]
		dwmapiExportByOrdinal37 endp
		dwmapiExportByOrdinal38 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[66 * 8]
		dwmapiExportByOrdinal38 endp
		dwmapiExportByOrdinal39 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[67 * 8]
		dwmapiExportByOrdinal39 endp
		dwmapiExportByOrdinal40 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[68 * 8]
		dwmapiExportByOrdinal40 endp
		dwmapiExportByOrdinal41 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[69 * 8]
		dwmapiExportByOrdinal41 endp
		dwmapiExportByOrdinal42 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[70 * 8]
		dwmapiExportByOrdinal42 endp
		dwmapiExportByOrdinal43 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[71 * 8]
		dwmapiExportByOrdinal43 endp
		dwmapiExportByOrdinal44 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[72 * 8]
		dwmapiExportByOrdinal44 endp
		dwmapiExportByOrdinal45 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[73 * 8]
		dwmapiExportByOrdinal45 endp
		dwmapiExportByOrdinal46 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[74 * 8]
		dwmapiExportByOrdinal46 endp
		dwmapiExportByOrdinal47 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[75 * 8]
		dwmapiExportByOrdinal47 endp
		dwmapiExportByOrdinal48 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[76 * 8]
		dwmapiExportByOrdinal48 endp
		dwmapiExportByOrdinal49 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[77 * 8]
		dwmapiExportByOrdinal49 endp
		dwmapiExportByOrdinal50 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[78 * 8]
		dwmapiExportByOrdinal50 endp
		dwmapiExportByOrdinal51 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[79 * 8]
		dwmapiExportByOrdinal51 endp
		dwmapiExportByOrdinal52 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[80 * 8]
		dwmapiExportByOrdinal52 endp
		dwmapiExportByOrdinal53 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[81 * 8]
		dwmapiExportByOrdinal53 endp
		dwmapiExportByOrdinal54 proc
			jmp QWORD ptr OriginalFuncs_dwmapi[82 * 8]
		dwmapiExportByOrdinal54 endp
		DwmpUpdateProxyWindowForCapture proc
			jmp QWORD ptr OriginalFuncs_dwmapi[83 * 8]
		DwmpUpdateProxyWindowForCapture endp
		DwmIsCompositionEnabled proc
			jmp QWORD ptr OriginalFuncs_dwmapi[84 * 8]
		DwmIsCompositionEnabled endp
		DwmModifyPreviousDxFrameDuration proc
			jmp QWORD ptr OriginalFuncs_dwmapi[85 * 8]
		DwmModifyPreviousDxFrameDuration endp
		DwmQueryThumbnailSourceSize proc
			jmp QWORD ptr OriginalFuncs_dwmapi[86 * 8]
		DwmQueryThumbnailSourceSize endp
		DwmRegisterThumbnail proc
			jmp QWORD ptr OriginalFuncs_dwmapi[87 * 8]
		DwmRegisterThumbnail endp
		DwmRenderGesture proc
			jmp QWORD ptr OriginalFuncs_dwmapi[88 * 8]
		DwmRenderGesture endp
		DwmSetDxFrameDuration proc
			jmp QWORD ptr OriginalFuncs_dwmapi[89 * 8]
		DwmSetDxFrameDuration endp
		DwmSetIconicLivePreviewBitmap proc
			jmp QWORD ptr OriginalFuncs_dwmapi[90 * 8]
		DwmSetIconicLivePreviewBitmap endp
		DwmSetIconicThumbnail proc
			jmp QWORD ptr OriginalFuncs_dwmapi[91 * 8]
		DwmSetIconicThumbnail endp
		DwmSetPresentParameters proc
			jmp QWORD ptr OriginalFuncs_dwmapi[92 * 8]
		DwmSetPresentParameters endp
		DwmSetWindowAttribute proc
			jmp QWORD ptr OriginalFuncs_dwmapi[93 * 8]
		DwmSetWindowAttribute endp
		DwmShowContact proc
			jmp QWORD ptr OriginalFuncs_dwmapi[94 * 8]
		DwmShowContact endp
		DwmTetherContact proc
			jmp QWORD ptr OriginalFuncs_dwmapi[95 * 8]
		DwmTetherContact endp
		DwmTransitionOwnedWindow proc
			jmp QWORD ptr OriginalFuncs_dwmapi[96 * 8]
		DwmTransitionOwnedWindow endp
		DwmUnregisterThumbnail proc
			jmp QWORD ptr OriginalFuncs_dwmapi[97 * 8]
		DwmUnregisterThumbnail endp
		DwmUpdateThumbnailProperties proc
			jmp QWORD ptr OriginalFuncs_dwmapi[98 * 8]
		DwmUpdateThumbnailProperties endp
else
	.model flat, C
	.stack 4096
	.code
		extern OriginalFuncs_dwmapi:DWORD
		DwmpDxGetWindowSharedSurface proc
			jmp DWORD ptr OriginalFuncs_dwmapi[0 * 4]
		DwmpDxGetWindowSharedSurface endp
		DwmpDxUpdateWindowSharedSurface proc
			jmp DWORD ptr OriginalFuncs_dwmapi[1 * 4]
		DwmpDxUpdateWindowSharedSurface endp
		DwmEnableComposition proc
			jmp DWORD ptr OriginalFuncs_dwmapi[2 * 4]
		DwmEnableComposition endp
		dwmapiExportByOrdinal proc
			jmp DWORD ptr OriginalFuncs_dwmapi[3 * 4]
		dwmapiExportByOrdinal endp
		dwmapiExportByOrdinal2 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[4 * 4]
		dwmapiExportByOrdinal2 endp
		dwmapiExportByOrdinal3 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[5 * 4]
		dwmapiExportByOrdinal3 endp
		dwmapiExportByOrdinal4 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[6 * 4]
		dwmapiExportByOrdinal4 endp
		dwmapiExportByOrdinal5 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[7 * 4]
		dwmapiExportByOrdinal5 endp
		dwmapiExportByOrdinal6 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[8 * 4]
		dwmapiExportByOrdinal6 endp
		dwmapiExportByOrdinal7 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[9 * 4]
		dwmapiExportByOrdinal7 endp
		dwmapiExportByOrdinal8 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[10 * 4]
		dwmapiExportByOrdinal8 endp
		DllCanUnloadNow proc
			jmp DWORD ptr OriginalFuncs_dwmapi[11 * 4]
		DllCanUnloadNow endp
		dwmapiExportByOrdinal9 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[12 * 4]
		dwmapiExportByOrdinal9 endp
		dwmapiExportByOrdinal10 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[13 * 4]
		dwmapiExportByOrdinal10 endp
		dwmapiExportByOrdinal11 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[14 * 4]
		dwmapiExportByOrdinal11 endp
		DllGetClassObject proc
			jmp DWORD ptr OriginalFuncs_dwmapi[15 * 4]
		DllGetClassObject endp
		DwmAttachMilContent proc
			jmp DWORD ptr OriginalFuncs_dwmapi[16 * 4]
		DwmAttachMilContent endp
		DwmDefWindowProc proc
			jmp DWORD ptr OriginalFuncs_dwmapi[17 * 4]
		DwmDefWindowProc endp
		DwmDetachMilContent proc
			jmp DWORD ptr OriginalFuncs_dwmapi[18 * 4]
		DwmDetachMilContent endp
		DwmEnableBlurBehindWindow proc
			jmp DWORD ptr OriginalFuncs_dwmapi[19 * 4]
		DwmEnableBlurBehindWindow endp
		DwmEnableMMCSS proc
			jmp DWORD ptr OriginalFuncs_dwmapi[20 * 4]
		DwmEnableMMCSS endp
		DwmExtendFrameIntoClientArea proc
			jmp DWORD ptr OriginalFuncs_dwmapi[21 * 4]
		DwmExtendFrameIntoClientArea endp
		DwmFlush proc
			jmp DWORD ptr OriginalFuncs_dwmapi[22 * 4]
		DwmFlush endp
		DwmGetColorizationColor proc
			jmp DWORD ptr OriginalFuncs_dwmapi[23 * 4]
		DwmGetColorizationColor endp
		dwmapiExportByOrdinal12 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[24 * 4]
		dwmapiExportByOrdinal12 endp
		DwmGetCompositionTimingInfo proc
			jmp DWORD ptr OriginalFuncs_dwmapi[25 * 4]
		DwmGetCompositionTimingInfo endp
		DwmGetGraphicsStreamClient proc
			jmp DWORD ptr OriginalFuncs_dwmapi[26 * 4]
		DwmGetGraphicsStreamClient endp
		DwmpGetColorizationParameters proc
			jmp DWORD ptr OriginalFuncs_dwmapi[27 * 4]
		DwmpGetColorizationParameters endp
		DwmpDxgiIsThreadDesktopComposited proc
			jmp DWORD ptr OriginalFuncs_dwmapi[28 * 4]
		DwmpDxgiIsThreadDesktopComposited endp
		DwmGetGraphicsStreamTransformHint proc
			jmp DWORD ptr OriginalFuncs_dwmapi[29 * 4]
		DwmGetGraphicsStreamTransformHint endp
		DwmGetTransportAttributes proc
			jmp DWORD ptr OriginalFuncs_dwmapi[30 * 4]
		DwmGetTransportAttributes endp
		DwmpSetColorizationParameters proc
			jmp DWORD ptr OriginalFuncs_dwmapi[31 * 4]
		DwmpSetColorizationParameters endp
		dwmapiExportByOrdinal13 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[32 * 4]
		dwmapiExportByOrdinal13 endp
		DwmGetUnmetTabRequirements proc
			jmp DWORD ptr OriginalFuncs_dwmapi[33 * 4]
		DwmGetUnmetTabRequirements endp
		DwmGetWindowAttribute proc
			jmp DWORD ptr OriginalFuncs_dwmapi[34 * 4]
		DwmGetWindowAttribute endp
		DwmpRenderFlick proc
			jmp DWORD ptr OriginalFuncs_dwmapi[35 * 4]
		DwmpRenderFlick endp
		DwmpAllocateSecurityDescriptor proc
			jmp DWORD ptr OriginalFuncs_dwmapi[36 * 4]
		DwmpAllocateSecurityDescriptor endp
		DwmpFreeSecurityDescriptor proc
			jmp DWORD ptr OriginalFuncs_dwmapi[37 * 4]
		DwmpFreeSecurityDescriptor endp
		dwmapiExportByOrdinal13 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[38 * 4]
		dwmapiExportByOrdinal13 endp
		dwmapiExportByOrdinal14 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[39 * 4]
		dwmapiExportByOrdinal14 endp
		dwmapiExportByOrdinal15 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[40 * 4]
		dwmapiExportByOrdinal15 endp
		dwmapiExportByOrdinal16 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[41 * 4]
		dwmapiExportByOrdinal16 endp
		dwmapiExportByOrdinal17 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[42 * 4]
		dwmapiExportByOrdinal17 endp
		DwmpEnableDDASupport proc
			jmp DWORD ptr OriginalFuncs_dwmapi[43 * 4]
		DwmpEnableDDASupport endp
		dwmapiExportByOrdinal18 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[44 * 4]
		dwmapiExportByOrdinal18 endp
		dwmapiExportByOrdinal19 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[45 * 4]
		dwmapiExportByOrdinal19 endp
		dwmapiExportByOrdinal20 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[46 * 4]
		dwmapiExportByOrdinal20 endp
		dwmapiExportByOrdinal21 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[47 * 4]
		dwmapiExportByOrdinal21 endp
		dwmapiExportByOrdinal22 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[48 * 4]
		dwmapiExportByOrdinal22 endp
		DwmInvalidateIconicBitmaps proc
			jmp DWORD ptr OriginalFuncs_dwmapi[49 * 4]
		DwmInvalidateIconicBitmaps endp
		dwmapiExportByOrdinal23 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[50 * 4]
		dwmapiExportByOrdinal23 endp
		dwmapiExportByOrdinal24 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[51 * 4]
		dwmapiExportByOrdinal24 endp
		dwmapiExportByOrdinal25 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[52 * 4]
		dwmapiExportByOrdinal25 endp
		dwmapiExportByOrdinal26 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[53 * 4]
		dwmapiExportByOrdinal26 endp
		dwmapiExportByOrdinal27 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[54 * 4]
		dwmapiExportByOrdinal27 endp
		dwmapiExportByOrdinal28 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[55 * 4]
		dwmapiExportByOrdinal28 endp
		DwmTetherTextContact proc
			jmp DWORD ptr OriginalFuncs_dwmapi[56 * 4]
		DwmTetherTextContact endp
		dwmapiExportByOrdinal29 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[57 * 4]
		dwmapiExportByOrdinal29 endp
		dwmapiExportByOrdinal30 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[58 * 4]
		dwmapiExportByOrdinal30 endp
		dwmapiExportByOrdinal31 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[59 * 4]
		dwmapiExportByOrdinal31 endp
		dwmapiExportByOrdinal32 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[60 * 4]
		dwmapiExportByOrdinal32 endp
		dwmapiExportByOrdinal33 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[61 * 4]
		dwmapiExportByOrdinal33 endp
		dwmapiExportByOrdinal34 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[62 * 4]
		dwmapiExportByOrdinal34 endp
		dwmapiExportByOrdinal35 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[63 * 4]
		dwmapiExportByOrdinal35 endp
		dwmapiExportByOrdinal36 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[64 * 4]
		dwmapiExportByOrdinal36 endp
		dwmapiExportByOrdinal37 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[65 * 4]
		dwmapiExportByOrdinal37 endp
		dwmapiExportByOrdinal38 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[66 * 4]
		dwmapiExportByOrdinal38 endp
		dwmapiExportByOrdinal39 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[67 * 4]
		dwmapiExportByOrdinal39 endp
		dwmapiExportByOrdinal40 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[68 * 4]
		dwmapiExportByOrdinal40 endp
		dwmapiExportByOrdinal41 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[69 * 4]
		dwmapiExportByOrdinal41 endp
		dwmapiExportByOrdinal42 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[70 * 4]
		dwmapiExportByOrdinal42 endp
		dwmapiExportByOrdinal43 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[71 * 4]
		dwmapiExportByOrdinal43 endp
		dwmapiExportByOrdinal44 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[72 * 4]
		dwmapiExportByOrdinal44 endp
		dwmapiExportByOrdinal45 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[73 * 4]
		dwmapiExportByOrdinal45 endp
		dwmapiExportByOrdinal46 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[74 * 4]
		dwmapiExportByOrdinal46 endp
		dwmapiExportByOrdinal47 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[75 * 4]
		dwmapiExportByOrdinal47 endp
		dwmapiExportByOrdinal48 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[76 * 4]
		dwmapiExportByOrdinal48 endp
		dwmapiExportByOrdinal49 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[77 * 4]
		dwmapiExportByOrdinal49 endp
		dwmapiExportByOrdinal50 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[78 * 4]
		dwmapiExportByOrdinal50 endp
		dwmapiExportByOrdinal51 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[79 * 4]
		dwmapiExportByOrdinal51 endp
		dwmapiExportByOrdinal52 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[80 * 4]
		dwmapiExportByOrdinal52 endp
		dwmapiExportByOrdinal53 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[81 * 4]
		dwmapiExportByOrdinal53 endp
		dwmapiExportByOrdinal54 proc
			jmp DWORD ptr OriginalFuncs_dwmapi[82 * 4]
		dwmapiExportByOrdinal54 endp
		DwmpUpdateProxyWindowForCapture proc
			jmp DWORD ptr OriginalFuncs_dwmapi[83 * 4]
		DwmpUpdateProxyWindowForCapture endp
		DwmIsCompositionEnabled proc
			jmp DWORD ptr OriginalFuncs_dwmapi[84 * 4]
		DwmIsCompositionEnabled endp
		DwmModifyPreviousDxFrameDuration proc
			jmp DWORD ptr OriginalFuncs_dwmapi[85 * 4]
		DwmModifyPreviousDxFrameDuration endp
		DwmQueryThumbnailSourceSize proc
			jmp DWORD ptr OriginalFuncs_dwmapi[86 * 4]
		DwmQueryThumbnailSourceSize endp
		DwmRegisterThumbnail proc
			jmp DWORD ptr OriginalFuncs_dwmapi[87 * 4]
		DwmRegisterThumbnail endp
		DwmRenderGesture proc
			jmp DWORD ptr OriginalFuncs_dwmapi[88 * 4]
		DwmRenderGesture endp
		DwmSetDxFrameDuration proc
			jmp DWORD ptr OriginalFuncs_dwmapi[89 * 4]
		DwmSetDxFrameDuration endp
		DwmSetIconicLivePreviewBitmap proc
			jmp DWORD ptr OriginalFuncs_dwmapi[90 * 4]
		DwmSetIconicLivePreviewBitmap endp
		DwmSetIconicThumbnail proc
			jmp DWORD ptr OriginalFuncs_dwmapi[91 * 4]
		DwmSetIconicThumbnail endp
		DwmSetPresentParameters proc
			jmp DWORD ptr OriginalFuncs_dwmapi[92 * 4]
		DwmSetPresentParameters endp
		DwmSetWindowAttribute proc
			jmp DWORD ptr OriginalFuncs_dwmapi[93 * 4]
		DwmSetWindowAttribute endp
		DwmShowContact proc
			jmp DWORD ptr OriginalFuncs_dwmapi[94 * 4]
		DwmShowContact endp
		DwmTetherContact proc
			jmp DWORD ptr OriginalFuncs_dwmapi[95 * 4]
		DwmTetherContact endp
		DwmTransitionOwnedWindow proc
			jmp DWORD ptr OriginalFuncs_dwmapi[96 * 4]
		DwmTransitionOwnedWindow endp
		DwmUnregisterThumbnail proc
			jmp DWORD ptr OriginalFuncs_dwmapi[97 * 4]
		DwmUnregisterThumbnail endp
		DwmUpdateThumbnailProperties proc
			jmp DWORD ptr OriginalFuncs_dwmapi[98 * 4]
		DwmUpdateThumbnailProperties endp
endif
end
