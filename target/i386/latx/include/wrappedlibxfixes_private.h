#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error Meh....
#endif

GO(XFixesChangeCursor, vFppp)
GO(XFixesChangeCursorByName, vFppp)
GO(XFixesChangeSaveSet, vFppiii)
GO(XFixesCopyRegion, vFppp)
GO(XFixesCreatePointerBarrier, pFppiiiiiip)
GO(XFixesCreateRegion, pFppi)
GO(XFixesCreateRegionFromBitmap, pFpp)
GO(XFixesCreateRegionFromGC, pFpp)
GO(XFixesCreateRegionFromPicture, pFpp)
GO(XFixesCreateRegionFromWindow, pFppi)
GO(XFixesDestroyPointerBarrier, vFpp)
GO(XFixesDestroyRegion, vFpp)
GO(XFixesExpandRegion, vFpppuuuu)
DATA(XFixesExtensionInfo, sizeof(void*))    //B
DATA(XFixesExtensionName, sizeof(void*))    //D
GO(XFixesFetchRegion, pFppp)
GO(XFixesFetchRegionAndBounds, pFpppp)
GO(XFixesFindDisplay, pFp)
GO(XFixesGetCursorImage, pFp)
GO(XFixesGetCursorName, pFppp)
GO(XFixesHideCursor, vFpp)
GO(XFixesIntersectRegion, vFpppp)
GO(XFixesInvertRegion, vFpppp)
GO(XFixesQueryExtension, iFppp)
GO(XFixesQueryVersion, iFppp)
GO(XFixesRegionExtents, vFppp)
GO(XFixesSelectCursorInput, vFppu)
GO(XFixesSelectSelectionInput, vFpppu)
GO(XFixesSetCursorName, vFppp)
GO(XFixesSetGCClipRegion, vFppiip)
GO(XFixesSetPictureClipRegion, vFppiip)
GO(XFixesSetRegion, vFpppi)
GO(XFixesSetWindowShapeRegion, vFppiiip)
GO(XFixesShowCursor, vFpp)
GO(XFixesSubtractRegion, vFpppp)
GO(XFixesTranslateRegion, vFppii)
GO(XFixesUnionRegion, vFpppp)
GO(XFixesVersion, iFv)

