inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����������õĻ���ģ��������Ȼ�������������õ�������
���������λ�õ�һ�㶼�Ƕ��Ž�����Ҫ�����µ����ǧ
��Ҫ��������Ŷ������С�����������������ĵ����뵱
��������Ҳֻ��ð��(fight)��һ���ˣ�һ��Ӯ�ˣ����������
�������������㡣
LONG);
        set("exits", ([
		"south" : __DIR__"dayuan4",
		"east" : __DIR__"sleep4",
		"west" : __DIR__"eatroom4",
        ]));
//      set("objects", ([
//              __DIR__"npc/xwzhu":1,
//      ]) );
	setup();
}

