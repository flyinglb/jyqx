inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������õĻ���ģ��������Ȼ�������������õ�������
���������λ�õ�һ�㶼�Ƕ��Ž�����Ҫ�����µ����ǧ
��Ҫ��������Ŷ������С�����������������ĵ����뵱
��������Ҳֻ��ð��(fight)��һ���ˣ�һ��Ӯ�ˣ����������
�������������㡣
LONG);
        set("exits", ([
		"west" : __DIR__"dayuan1",
		"south" : __DIR__"sleep1",
		"north" : __DIR__"eatroom1",
        ]));
//      set("objects", ([
//              __DIR__"npc/qlzhu":1,
//      ]) );
	setup();
}

