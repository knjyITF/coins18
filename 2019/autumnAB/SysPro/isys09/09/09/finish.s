
.Lformat_message:
        .string "Finished.\n"
.Lformat_eax:
        .string "eax=0x%08x (%d)\n"
.Lformat_ebx:
        .string "ebx=0x%08x (%d)\n"
.Lformat_ecx:
        .string "ecx=0x%08x (%d)\n"
.Lformat_edx:
        .string "edx=0x%08x (%d)\n"
.Lformat_esi:
        .string "esi=0x%08x (%d)\n"
.Lformat_edi:
        .string "edi=0x%08x (%d)\n"
.Lformat_eip:
        .string "eip=0x%08x\n"
.Lformat_esp:
        .string "esp=0x%08x\n"
.Lformat_ebp:
        .string "ebp=0x%08x\n"

        .text
.Ldump_and_exit:
        push   %ebp
        mov    %esp,%ebp

        /* message */
        push   $.Lformat_message
        call   printf
        add    $0x4,%esp

        /* eax */
        pushl  0x1c(%ebp)
        pushl  0x1c(%ebp)
        push   $.Lformat_eax
        call   printf
        add    $0xc,%esp

        /* ebx */
        pushl  0x18(%ebp)
        pushl  0x18(%ebp)
        push   $.Lformat_ebx
        call   printf
        add    $0xc,%esp

        /* ecx */
        pushl  0x14(%ebp)
        pushl  0x14(%ebp)
        push   $.Lformat_ecx
        call   printf
        add    $0xc,%esp

        /* edx */
        pushl  0x10(%ebp)
        pushl  0x10(%ebp)
        push   $.Lformat_edx
        call   printf
        add    $0xc,%esp

        /* esi */
        pushl  0xc(%ebp)
        pushl  0xc(%ebp)
        push   $.Lformat_esi
        call   printf
        add    $0xc,%esp

        /* edi */
        pushl  0x8(%ebp)
        pushl  0x8(%ebp)
        push   $.Lformat_edi
        call   printf
        add    $0xc,%esp

        /* eip */
        pushl  0x24(%ebp)
        push   $.Lformat_eip
        call   printf
        add    $0x8,%esp

        /* esp */
        lea    0x28(%ebp),%eax
        push   %eax
        push   $.Lformat_esp
        call   printf
        add    $0x8,%esp

        /* ebp */
        pushl  0x20(%ebp)
        push   $.Lformat_ebp
        call   printf
        add    $0x8,%esp

        /* exit() */
        push   $0x0
        call   exit

        .globl finish
finish:
        push   %ebp
        push   %eax
        push   %ebx
        push   %ecx
        push   %edx
        push   %esi
        push   %edi
        call   .Ldump_and_exit

