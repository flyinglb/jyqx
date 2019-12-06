inherit BULLETIN_BOARD;

void create()
{
        set_name("凌云的留言簿", ({ "board" }) );
        set("location", "/u/lingyun/workroom");
        set("board_id", "lingyun_b");
        set("long", "如果你有什么事或者有什么好的建议可以在\n" 
                    "这里(post)告诉随缘。\n\n");
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
