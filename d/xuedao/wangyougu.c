// wangyougu.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","���ǹ�");
        set("long",@LONG
�������Ǵ�������һ��Ƨ�����ڣ����¾����˼���ǰǰ���ᣬ���
СС���������������׵�ҫ�۵�ѩ�������š�����ɫ��ɽҰ��ѩ������
ҫ�ź�ɫ����ɫ�Ĺ��������ͷף��Թ�һ������¥�ɸ�������ǰ���֡�
����һ��С����֪ͨ���δ���
LONG );
        set("exits",([
                "south"   : __DIR__"sroad8",
                "southup" : __DIR__"sroad9",
        ]));
        set("objects", ([
                __DIR__"npc/zhuoma" :1,
                __DIR__"npc/yangzong" :1,
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

