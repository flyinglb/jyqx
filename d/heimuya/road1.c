//road1.c ����·
// by Xiang

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
	set("long", @LONG
����һ����ʯ�����Сɽ�ڣ��򶫱���ͨ��ƽ���ݵ�С·��
��˵ǰ��������Ұ�޳�û�����ɾ�����
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "northeast" : __DIR__"road2",
            "southwest" : __DIR__"road4",
            "west"  : __DIR__"linjxd1",
            "east"  : __DIR__"dating4",
        ]));
        set("objects",([  
           __DIR__"npc/laozhe" : 1 ,
        ])); 
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
