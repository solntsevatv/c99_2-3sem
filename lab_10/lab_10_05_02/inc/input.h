#ifndef _INPUT_H_
#define _INPUT_H_

#define OUT "out"
#define CAT "cat"
#define SPS "sps"
#define POS "pos"

typedef enum
{
    out,
    cat,
    sps,
    pos,
} args;

args read_arg(status_codes *code);
void read_list(node_t **list, status_codes *code);

#endif