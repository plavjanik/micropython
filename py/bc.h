typedef enum {
    MP_VM_RETURN_NORMAL,
    MP_VM_RETURN_YIELD,
    MP_VM_RETURN_EXCEPTION,
} mp_vm_return_kind_t;

// Exception stack entry
typedef struct _mp_exc_stack {
    const byte *handler;
    // bit 0 is saved currently_in_except_block value
    machine_uint_t val_sp;
    // We might only have 2 interesting cases here: SETUP_EXCEPT & SETUP_FINALLY,
    // consider storing it in bit 1 of val_sp. TODO: SETUP_WITH?
    byte opcode;
} mp_exc_stack;

mp_vm_return_kind_t mp_execute_byte_code(const byte *code, const mp_obj_t *args, uint n_args, const mp_obj_t *args2, uint n_args2, uint n_state, mp_obj_t *ret);
mp_vm_return_kind_t mp_execute_byte_code_2(const byte *code_info, const byte **ip_in_out, mp_obj_t *fastn, mp_obj_t **sp_in_out, mp_exc_stack *exc_stack, mp_exc_stack **exc_sp_in_out, volatile mp_obj_t inject_exc);
void mp_byte_code_print(const byte *code, int len);
