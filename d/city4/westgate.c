//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "长安城西门");
        set  ("long",  @LONG
这里是长安城的西门。东面就到了城中，远望人山人海，往来
行人车流不绝。西面一条大路通向远方。城门下有一些执勤的兵士。
时下虽已天下太平，但一干兵将还是英姿勃勃，警惕的盯着往来人
士。
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("exits",  ([  //sizeof()  ==  4
            "west"  :  "/d/xingxiu/xxroad1",
            "east"  :  __DIR__"center",
                "north"  : __DIR__"yizhan",
        ]));

        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
        setup();
        replace_program(ROOM);
}



