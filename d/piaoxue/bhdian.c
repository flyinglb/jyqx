inherit ROOM;
void create()
{
        set("short", "�׻���");
        set("long", @LONG
�����ǰ׻��õĻ���ģ��������Ȼ�������ǰ׻��õ�������
���������λ�õ�һ�㶼�Ƕ��Ž�����Ҫ�����µ����ǧ
��Ҫ��������Ŷ������С�����������������ĵ����뵱
��������Ҳֻ��ð��(fight)��һ���ˣ�һ��Ӯ�ˣ����������
�������������㡣
LONG);
        set("exits", ([
		"east" : __DIR__"dayuan2",
		"north" : __DIR__"sleep2",
		"south" : __DIR__"eatroom2",
        ]));
//      set("objects", ([
//              __DIR__"npc/bhzhu":1,
//      ]) );
	setup();
}

