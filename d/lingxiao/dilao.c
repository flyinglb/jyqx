//LUCAS 2000-6-18
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������ڼ����������棬��ȴ�е���������͸�롣������
�䣬һ����Ӱ�ֳ���������Ȼվ��ʯ���ԡ��չ�͸��������ֻ��
�����������׺�����Ŀ��࣬����΢�����������ССʯ��װ��
��������������Ƶģ��۹�ҫ�����磬������ٱ�� 
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "out" : __DIR__"didi",
        ]));
        set("objects", ([ 
                __DIR__"npc/bai" : 1,
        ])); 
        setup(); 
}

