//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "�����Ƕ���");
        set  ("long",  @LONG
�����ǳ����ǵĶ��š�����͵��˳��У�Զ����ɽ�˺�������
���˳�������������һ����·ͨ��Զ������������һЩִ�ڵı�ʿ��
ʱ����������̫ƽ����һ�ɱ�������Ӣ�˲���������Ķ���������
ʿ��
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("exits",  ([  //sizeof()  ==  4
                "west"  :  __DIR__"center",
                "east"  :  __DIR__"road4",
        ]));
        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  3,
        ]));
        set("outdoors",  "changan");
	set("no_clean_up",  0);
        setup();
	replace_program(ROOM);
}

