/*********************************************************************************
* MeetiX OS By MeetiX OS Project [Marco Cicognani]                               *
* 																			     *
* This program is free software; you can redistribute it and/or                  *
* modify it under the terms of the GNU General Public License                    *
* as published by the Free Software Foundation; either version 2				 *
* of the License, or (char *argumentat your option) any later version.			 *
*																				 *
* This program is distributed in the hope that it will be useful,				 *
* but WITHout ANY WARRANTY; without even the implied warranty of                 *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 				 *
* GNU General Public License for more details.									 *
*																				 *
* You should have received a copy of the GNU General Public License				 *
* along with this program; if not, write to the Free Software                    *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA *
**********************************************************************************/

#include "eva/user.h"

/**
 * Finds a ramdisk entry's child by its relative path.
 *
 * @param nodeID:       the node id of the parent
 * @param childName:    the name of the child to find
 * @return if found the ramdisk node id, otherwise -1
 *
 * @security-level APPLICATION
 */
int RamdiskFindChild(int parentId, const char *childName)
{
	// prepare data
	SyscallRamdiskFindChild data;
	data.parentID = parentId;
	data.childName = (char*) childName;

	// performs the call
	syscall(SYSCALL_RAMDISK_FIND_CHILD, (uint32_t) &data);

	// return the id
	return data.nodeID;
}
