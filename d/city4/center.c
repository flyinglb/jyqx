//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "ʮ�ֽ�ͷ");
        set  ("long",  @LONG
������ǳ����ǵ����ģ�������ֽ����ڴˡ�һ��Ρ��ߴ��
��¥������ǰ��������Щ���ơ�ÿ���峿�����������������ŵ�
���������򳤰��ǵĴ��С�·�ڳ�ˮ�����������˳����ϡ�
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

