#ifndef __SOUND_H__ // do not include more than once
#define __SOUND_H__
#include <stdint.h>

#define shootLength 4080
#define invaderKilledLength 3377

const uint8_t shoot[shootLength] = {
  129, 99, 103, 164, 214, 129, 31, 105, 204, 118, 55, 92, 140, 225, 152, 61, 84, 154, 184, 101, 
  75, 129, 209, 135, 47, 94, 125, 207, 166, 72, 79, 135, 195, 118, 68, 122, 205, 136, 64, 106, 
  143, 173, 105, 54, 122, 200, 133, 74, 106, 215, 236, 91, 43, 84, 163, 115, 34, 81, 150, 209, 
  184, 198, 191, 113, 95, 12, 0, 79, 167, 111, 120, 238, 255, 255, 118, 0, 0, 0, 0, 0, 
  89, 236, 255, 255, 255, 255, 190, 0, 0, 0, 20, 170, 161, 137, 255, 255, 255, 181, 37, 0, 
  0, 15, 0, 60, 167, 255, 255, 255, 255, 255, 60, 0, 0, 41, 60, 44, 128, 211, 255, 255, 
  255, 150, 51, 12, 0, 0, 10, 136, 201, 208, 236, 255, 255, 209, 0, 0, 0, 15, 16, 31, 
  128, 255, 255, 255, 255, 252, 144, 0, 0, 0, 77, 68, 75, 171, 255, 255, 255, 233, 139, 53, 
  0, 0, 9, 106, 77, 123, 209, 255, 255, 255, 146, 68, 7, 0, 0, 0, 136, 166, 159, 219, 
  255, 255, 255, 82, 0, 0, 0, 0, 0, 81, 214, 225, 229, 255, 255, 255, 115, 0, 0, 0, 
  75, 63, 47, 126, 209, 255, 255, 255, 222, 119, 54, 0, 0, 0, 112, 133, 103, 185, 255, 255, 
  255, 222, 136, 74, 0, 0, 0, 102, 96, 98, 177, 255, 255, 255, 255, 191, 119, 0, 0, 0, 
  44, 125, 116, 122, 222, 255, 255, 255, 236, 98, 50, 0, 0, 0, 17, 129, 208, 164, 194, 255, 
  255, 255, 198, 19, 0, 0, 0, 0, 40, 154, 205, 191, 209, 255, 255, 255, 147, 74, 20, 0, 
  0, 0, 112, 140, 119, 180, 255, 255, 255, 236, 211, 122, 0, 0, 0, 33, 85, 81, 123, 207, 
  255, 255, 255, 255, 255, 132, 0, 0, 0, 29, 31, 33, 115, 184, 255, 255, 248, 255, 255, 226, 
  33, 0, 0, 0, 55, 44, 58, 128, 215, 255, 243, 255, 255, 255, 226, 36, 0, 0, 0, 12, 
  31, 98, 170, 232, 225, 228, 255, 255, 255, 140, 39, 0, 0, 0, 0, 13, 96, 192, 192, 174, 
  242, 255, 255, 255, 207, 50, 0, 0, 0, 0, 0, 70, 149, 232, 192, 191, 248, 255, 255, 236, 
  140, 40, 0, 0, 0, 0, 24, 118, 208, 167, 163, 224, 255, 255, 255, 209, 137, 63, 10, 0, 
  0, 0, 88, 120, 115, 153, 181, 253, 255, 255, 228, 239, 219, 87, 0, 0, 0, 0, 22, 54, 
  130, 204, 200, 177, 238, 255, 255, 231, 208, 137, 75, 0, 0, 0, 0, 94, 105, 112, 178, 225, 
  204, 215, 255, 255, 255, 201, 112, 44, 10, 0, 0, 0, 91, 101, 115, 167, 214, 245, 232, 216, 
  255, 255, 225, 150, 63, 23, 0, 0, 0, 40, 101, 113, 140, 198, 216, 198, 219, 255, 255, 233, 
  180, 137, 81, 17, 0, 0, 0, 64, 78, 108, 154, 197, 240, 212, 207, 233, 255, 255, 209, 144, 
  71, 36, 0, 0, 0, 22, 103, 106, 136, 170, 200, 248, 221, 212, 233, 255, 255, 195, 112, 37, 
  6, 0, 0, 0, 27, 126, 128, 139, 173, 190, 224, 243, 221, 214, 233, 255, 221, 144, 54, 2, 
  0, 0, 0, 0, 67, 154, 177, 161, 173, 171, 214, 250, 221, 211, 225, 243, 204, 122, 48, 9, 
  3, 0, 0, 2, 75, 154, 167, 160, 177, 202, 218, 195, 195, 221, 249, 235, 188, 143, 105, 53, 
  0, 0, 0, 15, 63, 79, 133, 166, 202, 215, 174, 160, 191, 240, 229, 205, 200, 207, 204, 109, 
  20, 0, 0, 0, 0, 19, 89, 164, 174, 163, 168, 187, 216, 183, 171, 202, 211, 240, 212, 171, 
  154, 113, 68, 0, 0, 0, 0, 16, 54, 115, 152, 200, 214, 178, 157, 176, 201, 192, 177, 195, 
  218, 208, 168, 136, 87, 55, 2, 0, 0, 0, 55, 77, 108, 152, 180, 211, 198, 166, 170, 187, 
  195, 181, 185, 205, 218, 174, 149, 132, 91, 60, 0, 0, 0, 3, 64, 88, 108, 159, 198, 197, 
  181, 167, 177, 194, 173, 159, 184, 190, 214, 202, 160, 153, 140, 103, 34, 0, 0, 3, 6, 19, 
  71, 115, 166, 204, 184, 170, 183, 197, 166, 144, 152, 180, 204, 194, 174, 180, 185, 157, 132, 96, 
  60, 36, 0, 0, 0, 24, 78, 105, 125, 156, 185, 202, 177, 168, 168, 181, 170, 142, 154, 180, 
  201, 181, 167, 168, 171, 170, 128, 85, 44, 30, 16, 0, 3, 22, 58, 120, 137, 149, 173, 176, 
  194, 185, 164, 156, 156, 170, 146, 136, 161, 185, 191, 171, 156, 163, 168, 142, 108, 84, 60, 17, 
  0, 7, 29, 48, 55, 85, 128, 171, 183, 171, 178, 187, 178, 160, 147, 152, 160, 146, 133, 149, 
  168, 188, 170, 154, 159, 159, 156, 130, 109, 96, 68, 23, 5, 13, 23, 50, 71, 81, 106, 146, 
  168, 188, 191, 173, 171, 168, 174, 161, 139, 139, 147, 144, 132, 142, 159, 176, 174, 160, 153, 150, 
  147, 150, 128, 109, 91, 53, 44, 34, 15, 24, 40, 70, 82, 96, 126, 149, 180, 184, 178, 173, 
  174, 177, 166, 144, 144, 149, 150, 137, 126, 129, 143, 149, 153, 156, 163, 168, 149, 139, 136, 135, 
  136, 118, 106, 92, 74, 46, 26, 31, 44, 55, 60, 75, 91, 119, 146, 156, 166, 173, 183, 183, 
  168, 161, 159, 159, 156, 142, 139, 143, 143, 132, 128, 130, 139, 144, 137, 143, 152, 163, 160, 147, 
  140, 133, 136, 129, 116, 112, 118, 112, 89, 68, 50, 46, 53, 53, 58, 67, 84, 105, 105, 113, 
  136, 156, 170, 171, 173, 176, 177, 167, 160, 153, 153, 152, 140, 139, 142, 140, 140, 130, 132, 129, 
  137, 133, 128, 128, 135, 140, 142, 143, 147, 150, 146, 136, 130, 129, 126, 128, 116, 111, 113, 120, 
  119, 87, 46, 13, 0, 6, 53, 96, 139, 161, 200, 255, 255, 174, 82, 58, 55, 105, 219, 208, 
  82, 71, 70, 112, 235, 204, 79, 70, 71, 120, 239, 207, 79, 68, 67, 118, 242, 204, 78, 65, 
  65, 112, 242, 207, 78, 64, 60, 109, 243, 211, 77, 58, 57, 103, 245, 216, 81, 60, 58, 99, 
  232, 225, 82, 53, 58, 88, 221, 236, 98, 53, 58, 81, 205, 250, 118, 51, 55, 72, 183, 255, 
  139, 51, 57, 63, 167, 255, 164, 55, 54, 57, 143, 255, 191, 58, 53, 55, 115, 255, 214, 75, 
  51, 55, 96, 232, 243, 96, 44, 54, 78, 200, 255, 133, 47, 57, 63, 163, 255, 177, 53, 55, 
  55, 122, 255, 215, 64, 47, 51, 98, 238, 245, 98, 46, 60, 75, 191, 255, 150, 46, 53, 55, 
  142, 255, 201, 58, 48, 50, 101, 243, 243, 91, 44, 51, 70, 190, 255, 152, 46, 54, 58, 129, 
  255, 212, 68, 43, 50, 92, 222, 255, 116, 43, 54, 61, 164, 255, 187, 51, 46, 53, 102, 248, 
  246, 94, 41, 54, 65, 176, 255, 174, 48, 46, 54, 113, 255, 236, 81, 40, 54, 72, 177, 255, 
  168, 47, 48, 58, 111, 252, 245, 89, 46, 51, 71, 176, 255, 180, 50, 46, 54, 101, 235, 255, 
  106, 41, 54, 64, 152, 255, 207, 63, 39, 51, 88, 202, 255, 140, 40, 48, 55, 120, 255, 240, 
  82, 40, 53, 68, 163, 255, 191, 51, 46, 50, 94, 214, 255, 136, 40, 53, 57, 120, 255, 242, 
  88, 41, 54, 70, 156, 255, 207, 60, 43, 53, 85, 190, 255, 166, 46, 47, 60, 101, 222, 255, 
  125, 41, 48, 61, 122, 255, 243, 95, 37, 51, 70, 144, 255, 221, 67, 41, 54, 75, 164, 255, 
  200, 55, 43, 53, 84, 184, 255, 177, 50, 46, 57, 95, 201, 255, 156, 47, 47, 60, 101, 216, 
  255, 139, 44, 50, 61, 112, 224, 255, 126, 44, 51, 65, 113, 229, 255, 122, 39, 48, 63, 115, 
  236, 255, 120, 47, 48, 64, 119, 231, 255, 118, 43, 50, 68, 116, 229, 255, 128, 46, 47, 67, 
  112, 219, 255, 135, 47, 53, 63, 108, 205, 255, 154, 50, 48, 61, 98, 192, 255, 170, 50, 50, 
  58, 92, 173, 255, 195, 57, 39, 46, 77, 149, 255, 208, 65, 34, 51, 78, 137, 255, 233, 79, 
  41, 50, 72, 120, 232, 255, 112, 43, 47, 67, 106, 201, 255, 160, 47, 47, 60, 92, 170, 255, 
  200, 63, 46, 55, 82, 142, 255, 242, 91, 48, 50, 75, 118, 212, 255, 146, 48, 47, 63, 101, 
  167, 255, 201, 64, 47, 57, 84, 136, 243, 253, 106, 44, 55, 71, 111, 188, 255, 177, 55, 47, 
  55, 91, 146, 252, 243, 92, 47, 54, 77, 113, 191, 255, 168, 54, 48, 63, 92, 144, 250, 243, 
  96, 51, 50, 74, 106, 184, 255, 185, 57, 48, 54, 87, 133, 233, 255, 116, 50, 51, 65, 105, 
  164, 255, 214, 67, 48, 53, 84, 118, 200, 255, 160, 55, 51, 58, 95, 140, 242, 252, 108, 48, 
  51, 67, 101, 159, 255, 216, 71, 50, 50, 81, 113, 180, 255, 187, 57, 47, 53, 88, 122, 205, 
  255, 153, 50, 48, 61, 96, 135, 226, 255, 123, 51, 53, 65, 98, 144, 242, 240, 102, 48, 48, 
  72, 103, 146, 255, 232, 84, 50, 53, 74, 103, 156, 255, 222, 84, 51, 54, 79, 106, 159, 255, 
  224, 78, 53, 54, 75, 106, 154, 255, 226, 85, 51, 54, 75, 105, 152, 255, 228, 89, 51, 54, 
  74, 106, 147, 245, 238, 106, 50, 50, 74, 103, 139, 231, 250, 126, 53, 53, 65, 101, 129, 208, 
  255, 147, 54, 53, 61, 91, 120, 191, 255, 177, 61, 47, 57, 87, 115, 164, 255, 211, 71, 54, 
  53, 78, 109, 146, 243, 240, 108, 55, 55, 65, 105, 128, 202, 255, 156, 58, 51, 58, 98, 115, 
  171, 255, 208, 74, 51, 53, 79, 112, 143, 228, 253, 128, 55, 51, 64, 102, 122, 181, 255, 195, 
  67, 48, 57, 89, 111, 143, 233, 249, 123, 58, 55, 68, 102, 119, 176, 255, 195, 72, 51, 58, 
  84, 112, 136, 216, 255, 150, 55, 51, 60, 92, 115, 159, 253, 229, 99, 54, 58, 72, 103, 123, 
  178, 255, 195, 68, 53, 60, 81, 113, 136, 207, 255, 164, 61, 51, 58, 89, 119, 144, 225, 255, 
  137, 58, 54, 64, 94, 119, 154, 239, 240, 112, 54, 58, 68, 103, 119, 156, 246, 224, 96, 46, 
  48, 65, 101, 118, 159, 246, 224, 94, 50, 55, 65, 106, 122, 159, 248, 221, 99, 51, 55, 68, 
  105, 126, 156, 243, 228, 108, 55, 51, 70, 101, 122, 154, 231, 242, 128, 55, 55, 65, 98, 119, 
  144, 215, 255, 152, 60, 54, 63, 91, 119, 136, 194, 255, 181, 64, 51, 63, 85, 109, 126, 171, 
  255, 218, 94, 57, 58, 71, 108, 122, 153, 225, 245, 140, 57, 51, 67, 94, 118, 136, 187, 255, 
  192, 74, 53, 58, 82, 109, 126, 154, 229, 246, 130, 57, 57, 67, 95, 118, 132, 183, 255, 197, 
  77, 54, 60, 78, 106, 125, 150, 214, 255, 153, 61, 54, 63, 88, 116, 126, 166, 242, 226, 112, 
  58, 50, 67, 96, 120, 136, 180, 255, 202, 79, 54, 55, 71, 102, 122, 142, 195, 255, 181, 68, 
  53, 60, 79, 108, 125, 144, 198, 255, 171, 67, 50, 57, 85, 108, 126, 144, 202, 255, 168, 65, 
  50, 58, 85, 112, 128, 146, 197, 253, 173, 67, 50, 57, 82, 105, 123, 139, 190, 253, 185, 72, 
  50, 58, 79, 108, 126, 137, 177, 249, 207, 92, 58, 60, 72, 99, 119, 133, 161, 229, 236, 130, 
  58, 51, 67, 94, 113, 126, 147, 198, 252, 174, 67, 50, 61, 84, 105, 128, 136, 164, 243, 219, 
  103, 58, 53, 67, 96, 116, 130, 146, 198, 249, 170, 68, 50, 61, 79, 111, 126, 133, 163, 231, 
  229, 125, 58, 50, 64, 95, 112, 129, 140, 177, 248, 202, 92, 58, 54, 72, 99, 118, 132, 147, 
  190, 249, 187, 75, 53, 57, 81, 106, 118, 133, 144, 200, 255, 176, 67, 54, 60, 81, 109, 123, 
  137, 143, 197, 252, 173, 71, 53, 60, 81, 106, 118, 137, 143, 190, 250, 187, 77, 54, 63, 77, 
  102, 119, 133, 144, 177, 240, 202, 99, 54, 54, 74, 98, 118, 132, 137, 164, 224, 232, 132, 60, 
  48, 63, 94, 115, 126, 140, 152, 195, 249, 178, 72, 55, 55, 78, 109, 119, 135, 144, 168, 225, 
  228, 129, 63, 50, 63, 91, 112, 129, 139, 144, 188, 239, 200, 92, 60, 57, 71, 101, 119, 133, 
  143, 149, 197, 249, 180, 72, 53, 57, 70, 101, 113, 129, 136, 144, 197, 238, 167, 68, 50, 55, 
  77, 102, 118, 133, 140, 150, 197, 240, 170, 70, 57, 60, 81, 102, 116, 132, 142, 143, 190, 240, 
  187, 87, 53, 57, 72, 99, 118, 132, 143, 143, 173, 229, 212, 120, 60, 50, 68, 91, 115, 126, 
  136, 140, 156, 198, 239, 168, 72, 55, 58, 79, 106, 120, 133, 139, 143, 168, 224, 218, 132, 60, 
  48, 67, 91, 112, 125, 133, 143, 146, 176, 232, 204, 108, 55, 51, 71, 94, 113, 126, 139, 144, 
  144, 181, 232, 195, 103, 57, 53, 71, 95, 112, 129, 140, 140, 143, 174, 226, 204, 115, 57, 51, 
  71, 94, 112, 125, 135, 143, 143, 164, 209, 224, 146, 64, 51, 60, 79, 108, 123, 133, 140, 140, 
  150, 184, 229, 187, 89, 54, 54, 72, 96, 116, 129, 139, 137, 142, 160, 197, 229, 156, 68, 51, 
  55, 78, 106, 118, 130, 136, 140, 146, 161, 204, 221, 149, 64, 51, 63, 79, 105, 120, 129, 140, 
  142, 139, 160, 202, 221, 156, 64, 53, 60, 75, 102, 120, 130, 140, 144, 144, 154, 188, 224, 178, 
  89, 55, 54, 70, 95, 116, 125, 137, 143, 142, 142, 164, 204, 216, 144, 63, 51, 63, 84, 102, 
  118, 130, 136, 140, 143, 147, 171, 214, 198, 122, 60, 48, 65, 88, 112, 118, 132, 139, 139, 139, 
  143, 168, 209, 202, 128, 60, 50, 65, 87, 105, 120, 132, 139, 139, 143, 143, 160, 198, 212, 152, 
  70, 54, 60, 79, 101, 118, 130, 137, 137, 137, 142, 146, 174, 208, 194, 116, 57, 51, 71, 89, 
  111, 123, 128, 137, 140, 143, 147, 146, 177, 211, 184, 109, 57, 51, 70, 92, 111, 123, 136, 137, 
  137, 143, 143, 147, 171, 202, 198, 128, 61, 50, 63, 85, 108, 120, 132, 139, 140, 143, 143, 140, 
  152, 184, 208, 163, 89, 54, 54, 74, 96, 112, 128, 132, 140, 139, 143, 142, 140, 157, 184, 205, 
  159, 84, 58, 53, 72, 98, 116, 129, 139, 143, 142, 146, 140, 137, 147, 176, 201, 180, 111, 57, 
  51, 70, 92, 111, 125, 132, 140, 142, 144, 142, 140, 139, 154, 183, 205, 157, 84, 54, 51, 70, 
  92, 106, 125, 133, 136, 142, 140, 137, 136, 135, 144, 180, 200, 163, 98, 55, 50, 75, 89, 112, 
  125, 133, 139, 140, 143, 140, 139, 137, 135, 157, 188, 195, 144, 75, 55, 55, 81, 99, 115, 132, 
  137, 143, 142, 142, 139, 140, 136, 136, 153, 184, 197, 153, 84, 57, 55, 77, 98, 115, 128, 137, 
  142, 140, 144, 139, 136, 137, 139, 142, 161, 185, 185, 139, 74, 54, 64, 79, 102, 116, 129, 139, 
  139, 140, 144, 139, 140, 136, 135, 136, 150, 176, 192, 161, 96, 58, 53, 77, 96, 115, 123, 132, 
  142, 139, 139, 142, 142, 135, 137, 135, 130, 150, 177, 188, 160, 101, 58, 54, 72, 91, 111, 122, 
  135, 137, 143, 142, 142, 139, 136, 137, 135, 130, 133, 153, 176, 185, 149, 87, 61, 55, 77, 94, 
  112, 129, 135, 139, 139, 142, 140, 139, 136, 137, 135, 132, 128, 137, 161, 178, 183, 132, 75, 53, 
  60, 81, 101, 118, 130, 136, 140, 139, 143, 140, 135, 136, 137, 130, 129, 132, 128, 140, 167, 181, 
  167, 115, 70, 54, 67, 85, 108, 119, 136, 136, 142, 142, 139, 142, 140, 132, 135, 132, 130, 130, 
  126, 128, 147, 168, 183, 156, 106, 68, 57, 65, 92, 106, 123, 132, 136, 142, 140, 140, 137, 139, 
  133, 129, 133, 130, 125, 130, 130, 126, 146, 167, 176, 160, 113, 71, 55, 65, 87, 105, 119, 133, 
  139, 140, 140, 137, 140, 139, 130, 133, 130, 129, 132, 132, 128, 126, 130, 139, 154, 167, 174, 142, 
  95, 67, 57, 72, 95, 111, 126, 132, 140, 142, 140, 140, 139, 136, 137, 130, 135, 132, 128, 128, 
  128, 126, 130, 126, 132, 150, 163, 173, 161, 118, 79, 60, 67, 84, 102, 120, 129, 135, 140, 140, 
  142, 142, 140, 132, 135, 130, 130, 133, 129, 128, 126, 130, 130, 126, 125, 130, 137, 156, 163, 170, 
  146, 102, 74, 58, 72, 88, 109, 122, 130, 139, 140, 140, 139, 137, 136, 137, 130, 135, 132, 128, 
  129, 128, 132, 128, 126, 128, 125, 130, 130, 128, 135, 150, 159, 163, 163, 125, 91, 65, 63, 75, 
  95, 115, 123, 132, 140, 142, 143, 140, 139, 130, 132, 129, 128, 128, 123, 129, 129, 125, 123, 126, 
  126, 126, 125, 129, 125, 125, 125, 126, 135, 143, 154, 159, 157, 135, 102, 78, 61, 71, 89, 106, 
  120, 129, 137, 139, 143, 142, 142, 139, 139, 136, 132, 128, 133, 128, 128, 132, 128, 126, 132, 126, 
  126, 130, 128, 126, 126, 126, 128, 128, 128, 125, 129, 130, 139, 152, 152, 156, 150, 126, 99, 82, 
  65, 70, 89, 106, 120, 133, 139, 140, 143, 140, 139, 137, 139, 132, 136, 133, 129, 128, 133, 129, 
  128, 132, 128, 126, 125, 130, 128, 132, 128, 126, 130, 126, 126, 126, 125, 125, 125, 126, 128, 128, 
  128, 128, 128, 129, 142, 144, 150, 147, 144, 133, 108, 91, 79, 70, 77, 96, 106, 123, 133, 139, 
  144, 140, 140, 139, 137, 139, 132, 153, 176, 119, 102, 113, 113, 116, 130, 166, 122, 99, 130, 113, 
  132, 166, 118, 103, 130, 111, 136, 166, 115, 105, 129, 111, 132, 160, 120, 102, 128, 115, 130, 160, 
  120, 101, 129, 109, 130, 163, 119, 105, 128, 109, 130, 164, 116, 101, 129, 111, 130, 164, 116, 108, 
  129, 111, 128, 159, 119, 112, 129, 111, 125, 157, 120, 116, 128, 106, 126, 150, 130, 123, 120, 111, 
  120, 139, 146, 126, 113, 116, 119, 133, 153, 126, 106, 120, 113, 132, 160, 122, 102, 128, 109, 126, 
  163, 115, 111, 129, 109, 126, 154, 125, 119, 123, 111, 120, 139, 146, 126, 109, 120, 116, 133, 164, 
  118, 102, 128, 109, 126, 163, 119, 108, 129, 111, 125, 149, 130, 123, 118, 115, 122, 132, 159, 128, 
  108, 125, 111, 132, 164, 118, 109, 129, 111, 125, 150, 132, 128, 119, 112, 119, 132, 159, 123, 106, 
  128, 111, 128, 159, 120, 118, 125, 112, 122, 139, 150, 126, 111, 125, 115, 129, 164, 116, 112, 128, 
  111, 125, 144, 142, 128, 113, 118, 116, 130, 164, 120, 106, 126, 115, 126, 146, 139, 123, 113, 122, 
  116, 130, 166, 118, 106, 129, 112, 125, 144, 143, 129, 116, 119, 118, 130, 160, 116, 116, 125, 116, 
  126, 133, 154, 128, 109, 126, 116, 128, 153, 126, 120, 120, 118, 120, 132, 166, 122, 109, 126, 112, 
  120, 136, 139, 125, 109, 115, 118, 123, 154, 122, 116, 120, 112, 122, 129, 163, 119, 108, 123, 113, 
  125, 136, 152, 126, 112, 122, 118, 122, 150, 132, 125, 119, 116, 116, 130, 157, 119, 118, 123, 118, 
  122, 132, 159, 120, 109, 125, 115, 125, 137, 156, 123, 111, 123, 118, 126, 139, 142, 128, 116, 119, 
  118, 128, 147, 132, 122, 115, 118, 123, 128, 152, 128, 120, 125, 116, 116, 132, 153, 120, 120, 123, 
  118, 122, 128, 157, 122, 119, 125, 119, 123, 129, 159, 116, 116, 126, 119, 123, 129, 159, 116, 116, 
  126, 119, 120, 132, 159, 116, 118, 125, 119, 120, 132, 154, 118, 118, 123, 122, 123, 129, 153, 120, 
  120, 123, 118, 122, 128, 152, 120, 125, 125, 116, 123, 126, 144, 130, 120, 120, 113, 122, 126, 144, 
  137, 122, 118, 118, 123, 120, 135, 147, 125, 119, 119, 122, 120, 132, 154, 122, 115, 123, 118, 119, 
  132, 154, 119, 113, 123, 115, 126, 132, 146, 122, 125, 122, 115, 122, 125, 137, 143, 126, 119, 119, 
  125, 120, 132, 154, 122, 115, 126, 123, 122, 129, 153, 122, 119, 125, 119, 123, 126, 139, 142, 123, 
  119, 119, 125, 118, 132, 154, 118, 118, 125, 116, 126, 126, 140, 132, 125, 123, 116, 123, 120, 132, 
  154, 122, 113, 122, 118, 122, 128, 146, 126, 123, 122, 115, 126, 120, 132, 153, 116, 116, 123, 118, 
  122, 128, 142, 129, 123, 125, 116, 123, 120, 132, 153, 116, 116, 128, 116, 126, 126, 139, 137, 122, 
  120, 119, 122, 120, 132, 149, 120, 125, 125, 116, 129, 122, 129, 153, 122, 119, 125, 119, 128, 123, 
  136, 144, 128, 120, 118, 123, 123, 129, 142, 126, 122, 125, 119, 129, 118, 132, 149, 119, 123, 125, 
  119, 129, 122, 129, 153, 120, 120, 125, 119, 129, 128, 129, 150, 122, 122, 125, 120, 129, 125, 132, 
  139, 122, 120, 119, 125, 125, 129, 140, 137, 128, 120, 120, 126, 126, 126, 137, 137, 123, 122, 125, 
  125, 126, 129, 135, 137, 128, 120, 120, 123, 128, 128, 136, 137, 126, 120, 125, 125, 125, 125, 136, 
  140, 128, 120, 125, 125, 125, 125, 132, 144, 128, 115, 119, 116, 122, 123, 129, 144, 118, 115, 125, 
  118, 126, 120, 130, 144, 118, 122, 128, 116, 128, 122, 129, 140, 120, 125, 125, 119, 128, 123, 129, 
  136, 132, 125, 125, 122, 123, 128, 128, 129, 143, 123, 122, 125, 123, 128, 125, 125, 142, 120, 125, 
  125, 123, 128, 128, 128, 132, 136, 126, 122, 125, 123, 128, 125, 129, 143, 118, 125, 125, 123, 128, 
  128, 128, 132, 136, 126, 122, 125, 123, 128, 128, 129, 142, 119, 125, 125, 123, 128, 128, 128, 129, 
  137, 126, 122, 125, 125, 125, 126, 129, 142, 122, 126, 125, 123, 128, 125, 128, 129, 142, 119, 123, 
  125, 123, 123, 128, 128, 129, 137, 125, 125, 125, 123, 128, 128, 128, 132, 130, 123, 125, 125, 125, 
  126, 126, 126, 136, 126, 125, 125, 123, 123, 128, 128, 128, 137, 120, 123, 123, 123, 125, 129, 128, 
  128, 137, 120, 125, 125, 125, 123, 128, 128, 128, 136, 123, 123, 128, 119, 126, 128, 128, 128, 136, 
  123, 123, 128, 123, 123, 123, 123, 129, 136, 123, 125, 125, 119, 128, 128, 123, 130, 135, 129, 130, 
  120, 125, 125, 125, 125, 125, 129, 135, 125, 125, 125, 125, 123, 128, 128, 128, 137, 120, 123, 128, 
  125, 128, 128, 125, 125, 132, 125, 125, 125, 125, 126, 126, 126, 126, 126, 136, 126, 120, 126, 125, 
  123, 128, 128, 128, 136, 123, 125, 125, 123, 128, 123, 128, 128, 128, 133, 126, 125, 125, 125, 123, 
  128, 123, 128, 133, 123, 125, 125, 123, 128, 128, 128, 128, 128, 135, 123, 125, 125, 125, 125, 126, 
  126, 126, 130, 135, 125, 125, 125, 125, 125, 126, 126, 126, 130, 130, 125, 125, 125, 125, 126, 126, 
  126, 126, 130, 129, 125, 125, 125, 125, 126, 126, 126, 126, 132, 125, 125, 125, 125, 126, 126, 126, 
  126, 130, 130, 123, 129, 125, 125, 129, 125, 125, 125, 125, 129, 129, 125, 125, 125, 125, 126, 126, 
  126, 130, 129, 130, 126, 125, 125, 125, 125, 126, 129, 125, 129, 135, 125, 125, 129, 125, 125, 125, 
  129, 125, 129, 130, 123, 125, 129, 125, 129, 125, 125, 125, 129, 129, 130, 123, 125, 125, 125, 126, 
  126, 126, 122, 129, 128, 123, 123, 123, 122, 126, 122, 126, 128, 123, 128, 128, 128, 123, 128, 123, 
  128, 128, 128, 128, 128, 129, 129, 125, 129, 125, 125, 125, 125, 126, 126, 126, 130, 125, 125, 125, 
  126, 126, 126, 126, 128, 128, 128, 129, 125, 125, 125, 125, 126, 126, 126, 126, 126, 130, 129, 125, 
  125, 125, 125, 130, 125, 125, 129, 125, 129, 129, 125, 125, 125, 125, 126, 126, 126, 130, 125, 125, 
  129, 125, 125, 125, 125, 130, 125, 125, 125, 125, 130, 125, 129, 125, 129, 129, 125, 125, 129, 125, 
  129, 125, 129, 129, 125, 125, 125, 125, 129, 125, 125, 125, 126, 128, 128, 129, 125, 129, 125, 125};

const uint8_t invaderKilled[invaderKilledLength] = {
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 144, 164, 145, 111, 
  95, 91, 100, 106, 126, 134, 108, 109, 123, 160, 158, 118, 101, 144, 189, 110, 79, 154, 202, 117, 
  16, 96, 208, 187, 65, 100, 192, 175, 93, 0, 106, 253, 137, 17, 140, 242, 103, 1, 134, 255, 
  134, 4, 110, 230, 118, 1, 149, 255, 89, 6, 160, 255, 110, 0, 60, 177, 255, 81, 27, 207, 
  170, 43, 61, 200, 179, 23, 104, 245, 112, 11, 102, 210, 217, 39, 73, 237, 114, 29, 57, 173, 
  255, 91, 0, 145, 255, 138, 10, 62, 171, 252, 84, 0, 172, 244, 46, 47, 207, 190, 74, 0, 
  141, 255, 147, 16, 65, 191, 215, 30, 84, 224, 163, 78, 0, 128, 255, 124, 0, 149, 255, 102, 
  0, 138, 249, 169, 63, 0, 166, 255, 62, 24, 195, 229, 33, 78, 224, 163, 70, 0, 145, 255, 
  100, 0, 161, 255, 92, 0, 163, 255, 95, 0, 134, 246, 191, 77, 0, 125, 255, 130, 0, 88, 
  198, 226, 95, 0, 122, 255, 158, 43, 53, 213, 178, 21, 99, 214, 200, 49, 39, 198, 214, 75, 
  0, 131, 255, 134, 6, 104, 219, 179, 18, 105, 251, 104, 4, 106, 228, 204, 45, 51, 185, 247, 
  76, 0, 178, 244, 39, 52, 199, 220, 85, 0, 105, 255, 182, 35, 99, 254, 96, 0, 118, 207, 
  243, 84, 0, 137, 255, 124, 0, 140, 253, 121, 43, 19, 162, 255, 147, 15, 60, 180, 255, 62, 
  26, 196, 222, 91, 0, 135, 255, 96, 0, 178, 255, 76, 6, 179, 255, 80, 0, 166, 255, 108, 
  0, 110, 255, 92, 0, 122, 228, 215, 57, 24, 181, 252, 75, 0, 118, 255, 134, 1, 133, 214, 
  188, 65, 0, 163, 255, 95, 0, 143, 255, 126, 34, 48, 193, 255, 65, 22, 208, 201, 50, 31, 
  209, 199, 42, 70, 190, 251, 57, 11, 190, 221, 87, 0, 140, 255, 129, 27, 88, 209, 202, 54, 
  28, 186, 251, 94, 0, 144, 255, 82, 4, 190, 255, 60, 19, 202, 220, 42, 55, 212, 186, 35, 
  78, 221, 169, 27, 95, 213, 189, 75, 0, 146, 255, 113, 0, 169, 255, 83, 0, 118, 241, 164, 
  25, 107, 202, 212, 79, 0, 133, 255, 153, 42, 62, 216, 164, 7, 148, 229, 154, 54, 0, 185, 
  255, 65, 9, 197, 232, 54, 34, 189, 244, 80, 0, 113, 238, 210, 40, 90, 214, 159, 51, 2, 
  197, 218, 59, 31, 192, 255, 70, 8, 168, 255, 122, 0, 117, 235, 92, 7, 130, 234, 188, 16, 
  124, 229, 121, 46, 15, 178, 255, 104, 0, 142, 255, 87, 0, 156, 254, 131, 25, 100, 212, 183, 
  64, 6, 164, 255, 107, 8, 97, 179, 255, 99, 0, 121, 229, 155, 44, 87, 214, 181, 60, 35, 
  175, 255, 119, 15, 50, 167, 255, 98, 0, 171, 241, 113, 14, 97, 238, 127, 19, 159, 252, 91, 
  0, 162, 251, 126, 21, 102, 212, 172, 62, 15, 174, 255, 90, 0, 163, 229, 169, 49, 14, 189, 
  231, 78, 0, 147, 255, 127, 31, 120, 221, 148, 36, 86, 227, 127, 20, 131, 215, 195, 38, 70, 
  205, 178, 66, 0, 167, 255, 103, 5, 139, 215, 175, 73, 0, 176, 255, 122, 15, 104, 213, 164, 
  68, 0, 179, 255, 73, 22, 197, 245, 65, 0, 175, 255, 88, 0, 167, 242, 116, 39, 41, 198, 
  242, 67, 12, 171, 255, 105, 0, 149, 224, 142, 29, 88, 195, 198, 63, 0, 192, 241, 66, 10, 
  180, 255, 90, 0, 177, 250, 63, 24, 191, 236, 85, 0, 135, 247, 98, 29, 134, 222, 197, 50, 
  52, 200, 209, 58, 19, 196, 230, 59, 20, 175, 255, 103, 0, 158, 239, 80, 0, 148, 209, 206, 
  71, 0, 192, 234, 56, 28, 189, 255, 85, 0, 149, 237, 135, 51, 38, 174, 255, 92, 0, 145, 
  211, 150, 63, 7, 189, 255, 61, 17, 184, 255, 119, 21, 52, 182, 240, 63, 0, 190, 245, 86, 
  4, 126, 229, 169, 62, 55, 195, 246, 55, 13, 192, 243, 65, 0, 181, 251, 118, 42, 38, 187, 
  255, 68, 0, 186, 255, 131, 45, 29, 182, 255, 83, 0, 148, 211, 187, 81, 0, 181, 255, 84, 
  9, 158, 240, 91, 11, 181, 249, 99, 19, 117, 229, 107, 33, 121, 215, 206, 38, 87, 213, 153, 
  47, 47, 211, 177, 32, 119, 225, 128, 24, 145, 236, 91, 31, 121, 208, 215, 61, 0, 181, 255, 
  85, 2, 165, 228, 99, 28, 92, 213, 194, 39, 108, 211, 164, 66, 0, 189, 255, 109, 42, 53, 
  202, 227, 62, 20, 179, 255, 99, 20, 97, 192, 219, 59, 1, 190, 255, 84, 23, 83, 186, 255, 
  62, 0, 191, 236, 66, 0, 193, 242, 59, 28, 208, 212, 56, 30, 181, 255, 65, 8, 198, 221, 
  46, 31, 204, 203, 42, 63, 213, 176, 53, 49, 194, 251, 60, 6, 167, 246, 92, 19, 133, 199, 
  211, 60, 0, 170, 252, 126, 32, 104, 209, 149, 41, 81, 204, 192, 42, 74, 218, 159, 49, 73, 
  193, 250, 78, 0, 170, 235, 67, 15, 177, 252, 87, 31, 126, 195, 243, 68, 0, 180, 230, 64, 
  8, 158, 242, 130, 40, 109, 191, 223, 64, 0, 170, 228, 151, 47, 38, 200, 213, 63, 0, 152, 
  243, 167, 39, 124, 222, 105, 54, 43, 190, 255, 57, 14, 175, 235, 142, 28, 91, 194, 171, 46, 
  23, 201, 240, 69, 7, 143, 239, 145, 34, 157, 238, 79, 41, 86, 190, 255, 59, 0, 191, 234, 
  112, 40, 43, 197, 248, 57, 3, 194, 255, 70, 17, 191, 232, 83, 13, 107, 209, 190, 54, 41, 
  209, 217, 52, 25, 205, 239, 54, 20, 192, 251, 113, 29, 43, 190, 253, 52, 0, 145, 235, 165, 
  34, 133, 224, 116, 33, 94, 212, 165, 33, 99, 230, 109, 23, 182, 233, 110, 32, 106, 218, 148, 
  30, 128, 232, 86, 15, 191, 240, 96, 42, 73, 201, 252, 45, 6, 208, 238, 53, 0, 157, 247, 
  130, 41, 104, 190, 243, 42, 0, 176, 222, 140, 44, 6, 201, 255, 57, 0, 169, 216, 175, 49, 
  16, 217, 203, 32, 72, 213, 185, 45, 51, 226, 176, 36, 89, 201, 250, 69, 0, 177, 227, 53, 
  21, 152, 245, 149, 39, 94, 200, 250, 59, 0, 134, 216, 146, 27, 144, 224, 121, 45, 46, 214, 
  240, 31, 64, 225, 157, 40, 91, 205, 206, 43, 16, 212, 254, 75, 0, 160, 236, 78, 37, 118, 
  215, 215, 35, 68, 209, 196, 46, 2, 209, 241, 60, 1, 174, 249, 80, 38, 139, 213, 221, 43, 
  0, 182, 242, 134, 20, 100, 205, 161, 49, 5, 209, 255, 44, 34, 223, 219, 44, 21, 187, 255, 
  64, 25, 136, 225, 168, 15, 134, 204, 139, 34, 36, 210, 219, 50, 6, 216, 237, 34, 58, 209, 
  222, 53, 0, 188, 230, 140, 36, 65, 227, 142, 41, 86, 218, 211, 29, 82, 218, 165, 37, 51, 
  206, 239, 34, 3, 220, 214, 41, 33, 203, 255, 54, 4, 172, 232, 98, 25, 145, 212, 137, 28, 
  93, 209, 173, 42, 23, 224, 207, 27, 94, 219, 179, 50, 6, 198, 255, 97, 26, 149, 222, 92, 
  34, 103, 212, 212, 39, 27, 211, 252, 69, 0, 160, 225, 89, 30, 132, 219, 163, 37, 75, 218, 
  195, 39, 36, 228, 196, 32, 84, 226, 152, 25, 130, 209, 151, 39, 48, 228, 167, 40, 69, 209, 
  251, 38, 22, 214, 224, 35, 2, 170, 241, 104, 26, 161, 204, 178, 41, 0, 207, 250, 90, 23, 
  118, 224, 112, 33, 144, 222, 137, 51, 53, 206, 254, 55, 4, 183, 214, 132, 46, 5, 213, 255, 
  42, 30, 172, 231, 167, 32, 45, 213, 202, 17, 86, 227, 113, 49, 85, 213, 252, 29, 32, 229, 
  189, 40, 32, 191, 254, 83, 13, 165, 220, 73, 35, 108, 222, 208, 34, 63, 219, 213, 35, 14, 
  195, 235, 137, 43, 0, 201, 255, 45, 34, 159, 229, 161, 30, 83, 220, 162, 41, 54, 205, 248, 
  38, 19, 177, 224, 170, 31, 25, 226, 198, 31, 71, 215, 236, 38, 0, 206, 237, 52, 31, 216, 
  217, 34, 22, 218, 249, 74, 16, 156, 222, 62, 28, 216, 241, 68, 17, 142, 220, 89, 19, 191, 
  227, 81, 42, 84, 207, 255, 35, 0, 180, 207, 157, 33, 51, 223, 180, 38, 42, 226, 230, 23, 
  63, 222, 188, 40, 9, 205, 255, 66, 45, 107, 209, 252, 26, 0, 213, 227, 84, 18, 140, 213, 
  132, 51, 24, 208, 255, 65, 39, 213, 222, 40, 26, 115, 215, 242, 27, 21, 224, 225, 48, 11, 
  155, 229, 123, 47, 119, 220, 168, 23, 121, 212, 129, 46, 25, 204, 255, 77, 29, 170, 206, 124, 
  46, 24, 202, 255, 63, 37, 208, 219, 46, 17, 166, 223, 91, 35, 179, 228, 70, 41, 135, 215, 
  214, 22, 20, 230, 192, 28, 83, 214, 191, 30, 32, 227, 207, 30, 71, 229, 169, 40, 61, 199, 
  248, 70, 19, 153, 205, 123, 42, 78, 221, 193, 22, 104, 209, 169, 42, 6, 215, 246, 58, 41, 
  203, 218, 46, 17, 192, 221, 73, 41, 135, 227, 154, 45, 75, 202, 242, 59, 12, 173, 201, 45, 
  44, 149, 232, 171, 40, 72, 208, 230, 27, 10, 215, 203, 38, 45, 217, 226, 30, 31, 217, 210, 
  36, 26, 202, 223, 134, 45, 34, 227, 213, 32, 65, 221, 194, 36, 47, 198, 231, 115, 24, 93, 
  197, 170, 32, 54, 228, 179, 44, 56, 198, 238, 128, 44, 39, 213, 227, 23, 44, 218, 212, 46, 
  20, 163, 220, 104, 61, 101, 212, 245, 43, 26, 106, 201, 236, 30, 15, 213, 218, 55, 46, 122, 
  214, 203, 24, 73, 215, 163, 37, 66, 224, 174, 42, 69, 198, 235, 92, 42, 84, 200, 226, 27, 
  23, 212, 209, 65, 38, 151, 217, 98, 45, 188, 210, 94, 61, 70, 210, 242, 65, 47, 73, 203, 
  247, 27, 38, 145, 206, 219, 30, 16, 155, 224, 152, 44, 116, 203, 177, 37, 28, 198, 227, 82, 
  47, 153, 199, 123, 44, 103, 219, 130, 42, 169, 197, 120, 52, 41, 188, 239, 80, 49, 181, 206, 
  68, 45, 163, 196, 166, 35, 37, 227, 180, 41, 92, 221, 170, 41, 101, 211, 172, 46, 40, 199, 
  223, 53, 60, 138, 218, 182, 27, 106, 201, 130, 49, 49, 188, 234, 115, 46, 137, 203, 88, 49, 
  174, 196, 119, 53, 65, 210, 210, 31, 32, 194, 214, 72, 51, 198, 199, 50, 43, 167, 208, 79, 
  50, 188, 205, 85, 49, 136, 193, 160, 43, 33, 217, 220, 79, 55, 103, 206, 199, 36, 49, 219, 
  189, 41, 76, 213, 198, 36, 38, 183, 216, 99, 62, 89, 202, 234, 47, 40, 167, 198, 94, 45, 
  182, 194, 90, 60, 69, 214, 218, 44, 77, 210, 188, 33, 45, 139, 213, 205, 36, 50, 217, 191, 
  42, 43, 185, 215, 90, 69, 100, 204, 220, 34, 61, 208, 186, 41, 37, 168, 206, 128, 57, 113, 
  205, 172, 41, 68, 220, 163, 50, 83, 206, 215, 48, 41, 162, 194, 124, 62, 70, 190, 224, 65, 
  59, 205, 184, 41, 52, 208, 199, 61, 49, 145, 202, 112, 61, 147, 202, 142, 47, 105, 204, 147, 
  45, 100, 207, 156, 47, 89, 206, 176, 33, 106, 205, 116, 64, 85, 197, 218, 62, 59, 124, 200, 
  179, 33, 92, 207, 137, 49, 110, 194, 170, 40, 59, 219, 168, 47, 93, 206, 186, 39, 52, 149, 
  213, 184, 37, 66, 209, 191, 45, 42, 202, 184, 50, 73, 133, 224, 186, 35, 112, 191, 150, 45, 
  42, 201, 206, 70, 62, 160, 194, 118, 60, 105, 207, 172, 46, 67, 205, 195, 44, 72, 206, 181, 
  44, 49, 181, 200, 107, 66, 116, 198, 174, 43, 51, 164, 216, 121, 51, 175, 179, 89, 61, 95, 
  210, 158, 53, 100, 205, 186, 39, 51, 169, 206, 119, 65, 88, 183, 211, 59, 60, 200, 176, 59, 
  61, 116, 203, 190, 41, 75, 212, 177, 46, 59, 197, 196, 65, 68, 164, 195, 105, 57, 168, 181, 
  87, 66, 109, 201, 191, 40, 51, 192, 194, 120, 64, 80, 205, 203, 50, 54, 195, 182, 79, 73, 
  99, 210, 190, 50, 83, 203, 192, 45, 56, 174, 188, 86, 65, 196, 176, 46, 79, 208, 169, 49, 
  68, 193, 198, 100, 70, 84, 202, 199, 44, 65, 125, 207, 181, 51, 81, 200, 190, 47, 60, 172, 
  184, 84, 67, 188, 185, 84, 65, 144, 195, 107, 73, 111, 194, 206, 60, 61, 149, 184, 111, 60, 
  167, 177, 104, 69, 80, 206, 192, 58, 79, 199, 173, 55, 83, 140, 205, 175, 29, 47, 181, 184, 
  78, 83, 102, 195, 204, 54, 73, 107, 198, 187, 47, 78, 144, 205, 130, 60, 94, 189, 193, 66, 
  65, 114, 196, 152, 52, 135, 182, 137, 58, 68, 207, 196, 78, 69, 154, 182, 93, 73, 157, 187, 
  104, 77, 103, 182, 207, 69, 72, 192, 170, 64, 63, 166, 177, 90, 85, 105, 188, 204, 67, 75, 
  198, 171, 64, 76, 104, 198, 203, 65, 73, 121, 190, 177, 43, 72, 157, 197, 167, 50, 65, 202, 
  164, 66, 88, 145, 210, 138, 63, 95, 184, 190, 74, 68, 111, 191, 184, 42, 71, 201, 172, 57, 
  82, 149, 198, 174, 47, 64, 187, 180, 71, 87, 193, 159, 56, 82, 195, 173, 62, 82, 184, 179, 
  75, 75, 156, 184, 104, 69, 148, 181, 105, 74, 116, 192, 178, 50, 72, 168, 183, 97, 76, 139, 
  178, 150, 51, 92, 196, 153, 55, 80, 195, 183, 65, 87, 195, 147, 66, 89, 167, 191, 104, 76, 
  108, 191, 162, 53, 82, 189, 178, 67, 79, 117, 194, 189, 48, 70, 150, 185, 116, 69, 161, 166, 
  107, 78, 89, 196, 185, 57, 86, 192, 164, 62, 82, 169, 182, 96, 76, 157, 170, 121, 65, 114, 
  189, 117, 78, 108, 171, 197, 116, 60, 115, 180, 125, 71, 97, 189, 181, 60, 89, 195, 162, 63, 
  76, 149, 184, 120, 70, 162, 168, 80, 84, 155, 184, 105, 80, 110, 175, 184, 68, 83, 150, 177, 
  152, 49, 71, 187, 175, 96, 79, 97, 184, 181, 71, 84, 170, 171, 86, 84, 131, 192, 167, 52, 
  77, 167, 178, 111, 75, 91, 179, 185, 87, 81, 141, 179, 114, 83, 109, 173, 188, 85, 82, 112, 
  186, 170, 55, 91, 192, 163, 60, 78, 157, 181, 109, 84, 138, 185, 149, 61, 83, 171, 182, 117, 
  74, 88, 193, 174, 67, 86, 120, 191, 180, 52, 85, 168, 174, 90, 82, 180, 156, 85, 85, 111, 
  193, 164, 65, 99, 173, 176, 107, 71, 96, 187, 162, 65, 98, 184, 163, 72, 90, 185, 165, 72, 
  83, 156, 175, 123, 73, 116, 189, 133, 80, 115, 188, 159, 59, 86, 133, 197, 157, 63, 109, 182, 
  157, 58, 82, 157, 178, 121, 75, 92, 149, 194, 131, 68, 87, 159, 182, 106, 77, 121, 179, 135, 
  74, 107, 180, 160, 65, 91, 169, 169, 104, 78, 99, 179, 173, 73, 95, 185, 160, 74, 89, 128, 
  182, 163, 57, 93, 190, 159, 70, 86, 175, 159, 82, 98, 146, 186, 153, 63, 83, 180, 166, 86, 
  88, 144, 171, 121, 82, 106, 184, 164, 74, 93, 157, 171, 104, 84, 129, 181, 148, 64, 92, 138, 
  192, 166, 55, 87, 184, 152, 70, 93, 159, 176, 105, 88, 155, 160, 114, 80, 124, 181, 122, 82, 
  127, 179, 150, 66, 88, 173, 171, 87, 94, 151, 171, 133, 69, 106, 185, 131, 77, 103, 141, 197, 
  137, 73, 127, 167, 132, 70, 86, 163, 177, 105, 89, 134, 171, 133, 74, 106, 186, 143, 77, 105, 
  172, 166, 79, 88, 142, 170, 122, 80, 105, 146, 190, 135, 71, 95, 174, 156, 73, 98, 126, 186, 
  159, 65, 90, 141, 178, 139, 75, 101, 173, 156, 74, 98, 156, 168, 123, 75, 115, 176, 143, 69, 
  101, 185, 145, 75, 106, 183, 149, 75, 97, 160, 164, 96, 96, 167, 154, 101, 82, 140, 166, 100, 
  100, 119, 159, 179, 92, 94, 130, 176, 155, 63, 86, 157, 164, 104, 92, 133, 175, 143, 72, 102, 
  170, 150, 85, 99, 163, 165, 100, 91, 112, 149, 185, 117, 80, 129, 162, 111, 87, 140, 164, 111, 
  92, 142, 163, 128, 78, 113, 176, 141, 76, 98, 173, 162, 106, 91, 114, 179, 148, 74, 105, 163, 
  163, 100, 89, 145, 153, 99, 100, 136, 177, 127, 86, 114, 138, 184, 137, 69, 94, 163, 160, 93, 
  99, 122, 177, 156, 72, 94, 150, 164, 109, 96, 136, 171, 131, 82, 105, 147, 175, 105, 91, 151, 
  150, 104, 96, 107, 146, 184, 118, 88, 144, 152, 108, 95, 119, 177, 149, 72, 102, 124, 176, 165, 
  84, 96, 136, 165, 130, 80, 108, 171, 151, 82, 104, 141, 170, 133, 83, 103, 150, 172, 130, 81, 
  100, 169, 157, 98, 99, 113, 169, 159, 85, 107, 150, 162, 120, 87, 112, 171, 151, 77, 103, 169, 
  144, 93, 102, 139, 178, 124, 94, 115, 133, 181, 134, 77, 102, 162, 153, 93, 95, 114, 166, 150, 
  80, 105, 145, 163, 114, 90, 146, 147, 100, 101, 131, 171, 138, 79, 107, 128, 178, 152, 78, 95, 
  135, 163, 130, 86, 115, 167, 143, 88, 108, 154, 158, 117, 89, 108, 170, 153, 89, 102, 152, 148, 
  112, 99, 113, 173, 146, 90, 109, 143, 170, 121, 89, 108, 143, 171, 130, 82, 108, 170, 139, 80, 
  107, 130, 173, 158, 85, 106, 127, 169, 153, 80, 101, 148, 154, 109, 100, 136, 160, 121, 94, 117, 
  163, 147, 93, 105, 145, 160, 110, 100, 119, 160, 157, 96, 103, 117, 168, 147, 81, 105, 139, 165, 
  136, 86, 103, 158, 154, 101, 105, 147, 156, 115, 98, 116, 156, 153, 91, 107, 161, 145, 93, 109, 
  116, 147, 174, 106, 106, 118, 138, 168, 107, 95, 137, 149, 116, 96, 114, 163, 148, 93, 107, 133, 
  163, 139, 83, 105, 160, 147, 96, 110, 153, 146, 105, 105, 117, 141, 173, 133, 84, 113, 163, 132, 
  86, 109, 126, 165, 149, 97, 108, 127, 166, 146, 81, 108, 146, 138, 103, 107, 153, 144, 104, 109, 
  132, 164, 130, 97, 116, 152, 149, 102, 106, 129, 164, 137, 83, 105, 141, 160, 125, 96, 110, 140, 
  167, 121, 101, 116, 155, 145, 94, 108, 135, 159, 132, 88, 108, 138, 165, 130, 94, 118, 160, 137, 
  91, 108, 138, 156, 130, 97, 114, 160, 143, 91, 112, 150, 141, 102, 109, 150, 145, 104, 108, 150, 
  142, 109, 108, 127, 163, 136, 91, 110, 134, 161, 132, 96, 112, 148, 149, 111, 101, 130, 153, 125, 
  99, 113, 137, 168, 136, 90, 108, 143, 152, 115, 106, 125, 153, 138, 93, 122, 154, 127, 99, 125, 
  158, 119, 103, 116, 138, 167, 122, 97, 115, 149, 145, 105, 108, 136, 146, 113, 109, 118, 133, 172, 
  133, 93, 109, 139, 150, 113, 108, 134, 147, 128, 97, 112, 151, 147, 105, 115, 126, 142, 153, 107, 
  107, 122, 148, 147, 101, 108, 130, 153, 127, 101, 120, 148, 139, 106, 113, 127, 160, 139, 97, 109, 
  136, 152, 123, 105, 126, 154, 138, 94, 111, 139, 149, 123, 105, 119, 152, 143, 106, 110, 135, 146, 
  122, 105, 118, 153, 143, 108, 113, 116, 145, 145, 105, 111, 124, 153, 135, 93, 114, 150, 134, 102, 
  117, 124, 148, 150, 109, 112, 123, 151, 138, 96, 112, 124, 152, 142, 105, 112, 125, 154, 133, 102, 
  116, 126, 154, 145, 108, 111, 115, 141, 150, 110, 116, 122, 133, 158, 115, 111, 128};



#endif
