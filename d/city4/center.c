//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "十字街头");
        set  ("long",  @LONG
这里便是长安城的中心，四条大街交汇于此。一座巍峨高大的
钟楼耸立于前，很是有些气势。每到清晨，响亮的钟声便会伴着淡
淡雾气传向长安城的大街小巷。路口车水马龙，来往人潮不断。
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

        set("exits",  ([  //sizeof()  ==  4
            "north" :  __DIR__"club",
            "south" :  __DIR__"bank",
            "west"  :  __DIR__"westgate",
            "east"  :  __DIR__"eastgate",
        ]));
        set("objects",  ([  //sizeof()  ==  1
//             __DIR__"npc/libai"  :  1,
        ]));
        set("outdoors",  "changan");
        setup();
	replace_program(ROOM);
}

