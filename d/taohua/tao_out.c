#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�������һƬ��
���֣���������һ��Сͤ�ӡ�
LONG );
       set("exits", ([
           "south" : __DIR__"tingzi",
           "north" : __DIR__"tao0",
       ]));
       set("outdoors","taohua");
       set("no_clean_up", 0);
       setup();
}
void init()
{       object ob;
        mapping myfam;
        if( interactive( ob = this_player()))
        if(query("exits/north")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 100 )
        {
            delete("exits/north");
            set("exits/north", __DIR__"tao_in");
            return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "�һ���")
        {
            delete("exits/north");
            set("exits/north", __DIR__"tao_in");
            return ;
        }       
  	delete("exits/north");
        set("exits/north", __DIR__"tao0");
}
