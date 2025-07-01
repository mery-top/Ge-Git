#pragma once

char* sha_hash(char* blob, long size);
int save_blob(char* hash, char* blob, long size);