//LUCAS 2000-6-18
// laolang.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������Ǽ��������ȣ����߹صĶ��������Ƿ����Ź�ĵ�
�ӡ��˴����¸ߵͲ�ƽ�����߶��Ǿ�ʯ���ɣ�һ�����ؽ�������
�����ӵó�ȥ��ǽ�ϵ���һ֧֧��ѣ�����յ�����ǽ�ϵ�Ӱ��
��Ҫ���˶��ɵĹ���һ�������������ֵط����ǿ��߱ȽϺá�
LONG );
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);

        set("exits", ([
                "up" : __DIR__"jianyuting",
                "west" : __DIR__"jianyusun",
                "east" : __DIR__"jianyuzhu",
                "down" : __DIR__"didi",
        ]));
        set("objects", ([ 
                __DIR__"npc/dizi" : 1,
        ])); 
        setup(); 
        replace_program(ROOM);
}

