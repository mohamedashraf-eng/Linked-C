/**
 * @file Std_Types.h
 * @author Mohamed Ashraf (wx@wx.com)
 * @brief
 * @version 1.0.0
 * @date 2023-01-04
 * @details It contains all types that are used across everal modules of the
 * basic software and that are platform and compiler independent.
 *
 * @copyright Copyright (c) 2023
 *
 */
/** @brief Header Guards */
#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__
/** @brief Included headers */
#include "compiler.h"
#include "platform_types.h"


/*
 * ================================================================================================================================
 * -> File Version Information
 * ================================================================================================================================
 **/

/** @brief Vendor specific ID */
#define STD_VENDOR_ID (1332)
/** @brief Program based version */
#define STD_SW_MAJOR_VERSION (1)
#define STD_SW_MINOR_VERSION (0)
#define STD_SW_PATCH_VERSION (0)

/*
 * ================================================================================================================================
 * -> File Version Checks
 * ================================================================================================================================
 **/

#if ((STD_SW_MAJOR_VERSION != PLATFORM_SW_MAJOR_VERSION) ||                    \
     (STD_SW_MINOR_VERSION != PLATFORM_SW_MINOR_VERSION) ||                    \
     (STD_SW_PATCH_VERSION != PLATFORM_SW_PATCH_VERSION))
#error("`platform_types.h` and `std_types.h` version doesn't met.")
#endif
#if ((STD_SW_MAJOR_VERSION != COMPILER_SW_MAJOR_VERSION) ||                    \
     (STD_SW_MINOR_VERSION != COMPILER_SW_MINOR_VERSION) ||                    \
     (STD_SW_PATCH_VERSION != COMPILER_SW_PATCH_VERSION))
#error("`platform_types.h` and `compiler.h` version doesn't met.")
#endif

/*
 * ================================================================================================================================
 * -> Constants
 * ================================================================================================================================
 **/

/**
 * @brief This type can be used as standard API return type which is shared
 * between the RTE and BSW modules.
 * @implements Std_ReturnType_type
 */
typedef uint8 Std_ReturnType;
/**
 * @brief This type shall be sued to request the version of a BSW module using
 * the `"ModuleName"_GetVersionInfro()` function.
 * @implements Std_VersionInfoType_structure
 */
typedef struct {
  uint16 vendorID;
  uint16 moduleID;
  uint8 sw_major_version;
  uint8 sw_minor_version;
  uint8 sw_patch_version;
} Std_VersionInfoType;

#endif /* __STD_TYPES_H__ */