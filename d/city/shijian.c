inherit ROOM;

void create()
{
        set("short", "试剑厅");
        set("long", @LONG
这里是武庙之侧的演武厅，一股肃杀之气使你浑身一震。厅内众人
好象并不急着交手，似乎在期待什么。一旁的架子上摆着几把练习用
的竹剑。门上悬着一块匾额(sign)。
LONG
        );
        set("no_die", 1);
        set("no_get", 1);
        set("exits", ([
                 "south": __DIR__"wumiao",
]));
set("item_desc", ([
                "sign": @TEXT
   虹台论剑
天下归心
TEXT
        ]) );

        setup();
        replace_program(ROOM);
}
