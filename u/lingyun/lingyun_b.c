inherit BULLETIN_BOARD;

void create()
{
        set_name("���Ƶ����Բ�", ({ "board" }) );
        set("location", "/u/lingyun/workroom");
        set("board_id", "lingyun_b");
        set("long", "�������ʲô�»�����ʲô�õĽ��������\n" 
                    "����(post)������Ե��\n\n");
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
