// room: /d/xingxiu/saimachang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������С����������������ھ���ά�����ġ�����׷�����ݡ�
һ��С���ӿ�����һ�����ﲢ�����۵�һ���۷��㡣ȥ��·��С����
���ԶԹ����������������ʱ����������ñ��ӳ��С���ӡ���Ȼ��
�������ϲ�����С���ӣ���޾ͻ���Щ������Ļ�����С���Ӻ��ܵġ�
LONG );
        set("exits", ([ 
             "southeast" : __DIR__"beijiang",]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        set("objects", ([
                __DIR__"npc/alamuhan" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}

