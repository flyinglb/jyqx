//  /u/beyond/mr/npc/azhu.c ����
// this is made by beyond
// update 1997.6.23
#include <ansi.h>
inherit NPC; 
string ask_sword();
void create()
{
set_name("����", ({ "a zhu", "a", "zhu" }));
        set("gender", "Ů��");
        set("age", 20);              
	set("title",GRN"����Ѿ��"NOR);
	set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("per", 30);
        set("combat_exp", 14000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 50);
	set_skill("parry",50);
	set_skill("yanling-shenfa",50);
        set_skill("dodge", 50);
	set_skill("force",50);
	set_skill("shenyuan-gong",50);

	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");      
         
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();
        set("inquiry", ([
            "name" : "�Ҿ���Ľ�ݹ��ӵ�����Ѿ�߰��飬�þò������Ӳ�֪����û�С�\n",
            "here" : "����������ˮ鿣���Ľ����үΪ���չ��ң����Ұ��ŵ�ס����\n",
            "rumors" : "�����һ��������������룬Ҫȥ��ʩˮ���书�ؼ�����������ѽ��\n",
            "Ľ�ݸ�" : "Ľ�ݸ�����������������ˣ����Ա�֮������ʩ���������������\n",
            "��ʩˮ��" : "��ֻ֪����ʩˮ���ǹ��Ӳ���ĵط����ɲ�֪������ʲô�ط���\n",
            "����" : "�������ҵĺ���ü����ס������С��������һ���ǹ��ӵ�����Ѿ�ߡ�\n",   
            "����" : "��������������������﹩������ү�ӵ���λ����ǰ�����\n",       
            "����" : "������������ү�ӵ���λ��һ����ǰ�ı�������Ϊ���񽣣��������¶�Я��ٺƷ����������λǰ��\n",
            "����" : (: ask_sword :),
        ]));
}
string ask_sword()
{
mapping fam; 
// object ob
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
		return "��������ү�����ź��������������������úñ��ܣ��Ұ����ŵ������������ˣ�\n";
}

