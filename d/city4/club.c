//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "�����ַ�");
        set  ("long",  @LONG
�����ǳ�����һ�����������ֳ�������ҹĻ���ٺ�����͸�
�����֡����������Ŀ����д�ٹ��ˣ��������������ã��˼�����
�����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ���ɮ�˻�
��ʿ��
LONG);
       //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
       set("exits",  ([  //sizeof()  ==  4
              "up"    :  __DIR__"clubup",
              "south" :  __DIR__"center",
       ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"obj/tables"  :  1,
                __DIR__"obj/chairs"  :  2,
       ]));
//                set("outdoors",  "changan");
	set("no_clean_up",  0);
        setup();
	replace_program(ROOM);
}

