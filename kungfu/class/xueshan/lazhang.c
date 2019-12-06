// /kungfu/class/xueshan/lazhang.c  ���»�� 
// by secret 
 
#include <ansi.h> 
 
inherit NPC; 
inherit F_MASTER; 

string ask_for_join();

void create() 
{ 
        set_name("���»��", ({ "lazhang huofo", "huofo", "lazhang" })); 
        set("long",@LONG 
���»����ѩɽ���е��ĸ�ɮ���Է��о�����о��� 
����һ����ɫ���ģ�ͷ��ɮñ����ü��Ŀ���ƺ����޸���֮���� 
LONG 
        ); 
        set("title",HIY"���"NOR); 
        set("gender", "����"); 
        set("age", 50); 
        set("attitude", "peaceful"); 
        set("shen_type", -1); 
        set("str", 30); 
        set("int", 30); 
        set("con", 30); 
        set("dex", 30); 
        set("max_qi", 1000); 
        set("max_jing", 2500); 
        set("neili", 2000); 
        set("max_neili", 2000); 
        set("jiali", 50); 
        set("combat_exp", 400000); 
        set("score", 40000); 
 
        set_skill("lamaism", 130); 
        set_skill("literate", 120); 
        set_skill("force", 100); 
        set_skill("xiaowuxiang", 100); 
        set_skill("dodge", 120); 
        set_skill("shenkong-xing", 110); 
        set_skill("unarmed", 140); 
        set_skill("yujiamu-quan", 140); 
        set_skill("parry", 120); 
        set_skill("sword", 100); 
        set_skill("mingwang-jian", 100); 
 
        map_skill("force", "xiaowuxiang"); 
        map_skill("dodge", "shenkong-xing"); 
        map_skill("unarmed", "yujiamu-quan"); 
        map_skill("parry", "mingwang-jian"); 
        map_skill("sword", "mingwang-jian"); 
 
        create_family("ѩɽ��", 3, "���"); 
        set("class", "bonze"); 

        set("inquiry",([
                "���"  : (: ask_for_join :),
                "����"  : (: ask_for_join :),
        ]));

        setup(); 
 
        carry_object("/d/xueshan/obj/y-jiasha")->wear(); 
        carry_object("/d/xueshan/obj/sengmao")->wear(); 
 
        add_money("silver",100);
} 
 
 
void attempt_apprentice(object ob) 
{ 
 
        if ((string)ob->query("gender") != "����") { 
                command("say ��ϰ�����ڹ���Ҫ����֮�塣"); 
                command("say ��λ" + RANK_D->query_respect(ob) + 
                        "������ذɣ�"); 
                return; 
        } 
 
        if ((string)ob->query("class") != "bonze") { 
                command("say �ҷ��ŵ����������ࡣ"); 
                command("say ��λ" + RANK_D->query_respect(ob) + 
                        "������ذɣ�");
                ob->set_temp("pending/join_bonze", 1);
                command("say ʩ������������ҷ𣬾������(kneel)�ܽ䡣\n");

                return; 
        } 
 
        if ((string)ob->query("family/family_name") != "ѩɽ��")        { 
                command("say ��λ" + RANK_D->query_respect(ob) + 
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                command("say ��λ" + RANK_D->query_respect(ob) + 
                        "�����ȸ����ײ�ʦ��ѧϰ��");

                return; 
        } 
 
        if ((int)ob->query_skill("lamaism", 1) < 50) { 
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�"); 
                command("say ��λ" + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");

                return; 
        } 
 
        command("smile"); 
        command("nod"); 
        command("say �������ѧϰ�𷨰ɣ�"); 
        command("recruit " + ob->query("id")); 
 
        ob->set("title",HIY"������"NOR); 
}

void init()
{
        add_action("do_kneel", "kneel");

}

string ask_for_join()
{
        object me;

        me = this_player();

        if( (string)me->query("class")=="bonze" )
                return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";

        if( (string)me->query("gender") != "����" )
                return "ʩ��������������ǿ�ϲ�ɺأ���ϧ����ֻ����ͽ��\n";

        me->set_temp("pending/join_bonze", 1);
        return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
        object me = this_player();

        if( !me->query_temp("pending/join_bonze") )
                return 0;

        message_vision(
                "$N˫�ֺ�ʮ�����������ع���������\n\n"
                "$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",
                me, this_object() );

        command("smile");

        me->set("class", "bonze");

        return 1;
}

