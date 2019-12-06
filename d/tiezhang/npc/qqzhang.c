//qqzhang.c ��ǧ��
#include <ansi.h>

inherit NPC;
int ask_qiubai();
int ask_naogui();
void create()
{
    set_name("��ǧ��", ({ "qiu qianzhang", "qiu", "qianzhang", "zhang" }));
	set("long", 
        "����һ��������ͷ�����Ƹ�������㴩��Ь�����ֻ���һ�Ѵ����ȡ�\n"
	"���������ͻ������ı��顣\n");
        set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
        set("str", 23);
	set("int", 30);
	set("con", 26);
        set("dex", 25);
        set("env/wimpy", 70);
       
        set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 80);
	set("combat_exp", 100000);
	set("score", 40000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("strike", 60);
	set_skill("parry", 60);
	set_skill("literate", 60);
        set_skill("tiezhang-zhangfa", 60);
        set_skill("guiyuan-tunafa", 60);
        set_skill("shuishangpiao", 60);
        
        map_skill("force", "guiyuan-tunafa");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "tiezhang-zhangfa");
        map_skill("dodge", "shuishangpiao");
        prepare_skill("strike", "tiezhang-zhangfa");

    create_family("���ư�", 14, "����");

    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
        YEL"��ǧ����ɫ�����������������ˣ����ȥ����������������ʮ���գ����ɼ��磬����С��������\n\n"NOR,
        YEL"��ǧ�𼱵������ٲ�ס�֣�үү�ɾ�Ҫ�������ˣ�����\n\n"NOR,
    (: random_move :)
    }) );

	
    set("inquiry", ([
"name" : "�ǵ��ȸ����������һ����������ô��ǧ�ɡ��������Ų�������Ҳ���ѵ�������\n",
"here" : "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������\n",
"�Ϲٽ���" : (: ask_qiubai :),
"�ֹ�" : (: ask_naogui :),
    ]));
    setup();

    set("chat_chance", 10);
    set("chat_msg", ({
    "��ǧ�ɴ�����ֵ�˵���������ư��������µ����飬û��үү��֪���ģ���\n",
    "��ǧ�����ص�˵����������������һ����Ĺ����˵���ﾭ���ֹ���\n",
    "��ǧ�����ص�˵������һ���ڹ������гɣ��Ϳ��Դӻ�����ľ�в���������ˣ���\n",
    "��ǧ��˵��������ָ��ڶ�ָ�ڴ�����һ�����ص����ڣ���˵���ѹʰ��������֮������\n",
    (: random_move :)
    }) );
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > 0) {
                command("hehe");
                command("say ����ģ�үү������������Ĵ������С���˵�����");
            return;
        }
                command("haha");
                command("say үү���书�������������޺úø�����ѧ��׼û��");
                command("recruit " + me->query("id"));
}
int ask_qiubai()
{
say("�������ư�ĵ�ʮ������������˵ʮ��ǰ���˰��㣬���ں�������֪�����Ǽ٣�\n");
return 1;
}
int ask_naogui()
{
say("��һЩ����˵�����������������ϵķ�Ĺ�У������������ٺ٣�һ����ʲô���������棡\n");
  this_player()->set_temp("marks/��1", 1);
return 1;
}

int accept_fight(object me)
{
 command("say " + RANK_D->query_respect(me) + 
"���ǻ����ˣ�����������үү��ѵ��ѵ�㣡��\n");
command("say ��Ӵ����⣬��⣬�������治���ɣ����һ�ᣬ�Ҷ���ʹ��Ҫ������\n");
return 0;
}

