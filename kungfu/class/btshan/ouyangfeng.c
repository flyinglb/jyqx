///ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int ask_job();
void create()
{
	set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
		   +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
		   +"����ң�������ͷɢ����\n");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 53);
	set("nickname", HIR "����" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

        set("inquiry", ([
                "job"      :(:ask_job:),
        ]) );

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1500000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",170);
	set_skill("training",150);
	set_skill("staff", 170);
	set_skill("hamagong", 200);
	set_skill("chanchu-bufa", 170);
	set_skill("shexing-diaoshou", 170);
	set_skill("lingshe-zhangfa", 170);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	create_family("����ɽ��",1, "��ɽ��ʦ");
        set("chat_chance",2);
        set("chat_msg",({
         "ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
         "ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
         "ŷ������������ն����������ģ�\n",
        }));
	setup();
	carry_object("/d/baituo/obj/shezhang")->wield();
        carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/book/staff_book2");
	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<100000)
        {
          message_vision("ŷ�����$NЦ������ľ���̫����,�һ��������㣡\n",ob);
	return ;
         }
   message_vision("ŷ��������$N��ͷ��΢΢���˵�ͷ��\n",ob);
   command("recruit " + ob->query("id"));
   return;
}

int ask_job()
{
        object who = this_player();
        int pot = (int)(who->query("potential")) - (int)(who->query("learned_points"));

        if (who->query("family/family_name")!="����ɽ��"){
        write(name()+"�ߵ����㲻�ǰ���ɽ���ӣ����ﲻ��Ҫ���˰��֣�\n");
                return 1;
        }
        if(who->query_temp("job_btshan")) {
        write(name()+"����˵�����㲻�ǻ�������ô����ȥ������Ļ\n");
        return 1;
        }
        if(pot >= who->query_int() * 30 ) {
        write(name()+"����˵��������ȥæ�����Լ�������ɣ�\n");
        return 1;
        }
        if(who->query("combat_exp") > 500000 ) {
        write(name()+"����˵������ľ���̫�ߣ������������������ɣ�\n");
        return 1;
        }
        who->set_temp("job_btshan",1);
        message_vision(name()+"��$N˵�����ðɣ���ȥ���Ϲ�Ҫ�������ɣ���\n", who);
        return 1;
}
