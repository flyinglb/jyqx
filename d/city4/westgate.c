//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "����������");
        set  ("long",  @LONG
�����ǳ����ǵ����š�����͵��˳��У�Զ����ɽ�˺�������
���˳�������������һ����·ͨ��Զ������������һЩִ�ڵı�ʿ��
ʱ����������̫ƽ����һ�ɱ�������Ӣ�˲���������Ķ���������
ʿ��
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



