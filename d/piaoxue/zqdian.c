inherit ROOM;
void create()
{
        set("short", "��ȸ��");
        set("long", @LONG
��������ȸ�õĻ���ģ��������Ȼ����������ȸ�õ�������
���������λ�õ�һ�㶼�Ƕ��Ž�����Ҫ�����µ����ǧ
��Ҫ��������Ŷ������С�����������������ĵ����뵱
��������Ҳֻ��ð��(fight)��һ���ˣ�һ��Ӯ�ˣ����������
�������������㡣
LONG);
        set("exits", ([
		"north" : __DIR__"dayuan3",
		"east" : __DIR__"sleep3",
		"west" : __DIR__"eatroom3",
        ]));
//      set("objects", (
//              __DIR__"npc/zqzhu":1,
//      ]) );
	setup();
}

