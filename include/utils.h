#pragma once

void sha_hash(char* blob, long size, char* hash);
int save_blob(char* hash, char* blob, long size);
void write_object(char* type, char* content, long data_size, char* sha_hash);
void read_file_content(char* filename, char* content, long* size);