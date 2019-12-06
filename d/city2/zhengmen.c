// Room: /city2/zhengmen.c

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "�ʹ�����");
	set("long", @LONG
����ǻʹ����š�Ρ����ΰ�ĳ�ǽ�ϣ�'�Ͻ���'��������ʮ�����ۣ�
���ƻԻ͡�һ�����ߵĸ�ʾ(gaoshi)����ǽ�ϣ����ٱ��������ԡ�
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"bridge",
		"north" : "/d/huanggon/qihedian",
	]));
        set("objects", ([
                "/d/huanggon/npc/shiwei" : 1,
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	set("outdoors", "city2");
//	set("no_clean_up", 0);
	setup();
}

string look_gaoshi()
{
	return "\n������ػ�һ�ڷ���! \n�ٱ�һ�ˣ��ͽ�ʮ��;\n"
          "׽��һ�ˣ��ͽ������\n֪�鲻���ߣ���ն!\n���ݷ�\n";
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
if(dir=="north")
 {
     if( this_player()->query("huanggong\\canenter") )
        {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop")&& (inv[i]->query("equipped")))
		if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
                    return notify_fail("�佫��ǰ��ס�㣬����˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�\n"
                        "���óֱ����빬��\n");
                else if(objectp(present("guan bing", environment(me)))&&living(present("bing", environment(me))))
                    return notify_fail("�ٱ���ǰ��ס�㣬����˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�\n"
                        "���óֱ����빬��\n");
	return ::valid_leave(me, dir);
        }
     else
     {
     if (me->query("gender") == "Ů��") {
        if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
            return notify_fail("�佫��ǰ��ס��,����˵�����ʹ��صأ���" 
            "��Ѱ���̻�Ů�����ɳ���,\n" + RANK_D->query_respect(me) +"��أ����"
                "��ȡ���衣\n");
        else if(objectp(present("guan bing", environment(me))))
            return notify_fail("�ٱ���ǰ��ס�㣬����˵�����ʹ��صأ���" 
            "��Ѱ���̻�Ů�����ɳ���,\n" + RANK_D->query_respect(me) +"��أ����"
            "��ȡ���衣\n");
    	}
     if (me->query("gender") == "����") {
        if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
            say("�佫Ц������˵������λ�����������ˣ�������ɡ�\n");
        else if(objectp(present("guan bing", environment(me)))&&living(present("bing", environment(me))))
            say("�ٱ�Ц������˵������λ�����������ˣ�������ɡ�\n");
    	}
     if (me->query("gender") == "����") {
        if(objectp(present("wu jiang", environment(me)))&&living(present("wu", environment(me))))
            return notify_fail("�佫������ס������˵�����ʹ��صأ���" 
            "��Ѱ�����Ұ�����ɳ���.\n" + RANK_D->query_respect(me) +"��أ����"
                "��ȡ���衣\n");
        else if(objectp(present("guan bing", environment(me)))&&living(present("bing", environment(me))))
            return notify_fail("�ٱ�������ס������˵�����ʹ��صأ���" 
            "��Ѱ�����Ұ�����ɳ���\n" + RANK_D->query_respect(me) +"��أ����"
            "��ȡ���衣\n");
    	}
      }
}	
return ::valid_leave(me, dir);
}

