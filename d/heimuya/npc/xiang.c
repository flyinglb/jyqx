// xiang.c
#include <ansi.h>
inherit NPC;
int ask_kill();

void create()
{
    set_name("������", ({ "xiang wentian", "xiang"}));
    set("nickname", HIR "��������" NOR );
    set("gender", "����");
    set("title", "������̹�����ʹ");
    set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��\n");
    set("age", 45);
    set("shen_type", -1);

    set("str", 21);
    set("per", 28);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
    set("chat_chance", 1);
    set("inquiry", ([
      "����ͤ"     : "�����ˣ���ɱ��\n",
      "��������"   : "��λ��ͽ���ҷ�ɱ�������ɣ�\n",
      "ɱ��������" : (: ask_kill() :),
      "������"     : "��������������ʮ��......\n",
    ]));
    set("qi", 4000);
    set("max_qi", 4000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 350);

    set("combat_exp", 2500000);
    set("score", 0);

    set_skill("force", 110);
    set_skill("hunyuan-yiqi", 110);
    set_skill("dodge", 110);
    set_skill("shaolin-shenfa", 110);
    set_skill("finger", 110);
    set_skill("strike", 110);
    set_skill("hand", 110);
    set_skill("claw", 110);
    set_skill("parry", 110);
    set_skill("nianhua-zhi", 110);
    set_skill("sanhua-zhang", 110);
    set_skill("fengyun-shou", 110);
    set_skill("longzhua-gong", 110);
    set_skill("buddhism", 110);
    set_skill("literate", 110);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("finger", "nianhua-zhi");
    map_skill("strike", "sanhua-zhang");
    map_skill("hand", "fengyun-shou");
    map_skill("claw", "longzhua-gong");
    map_skill("parry", "nianhua-zhi");

    prepare_skill("finger", "nianhua-zhi");
    prepare_skill("strike", "sanhua-zhang");
    create_family("�������", 2, "������ʹ");

    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
    command("say �Ҳ��յ��ӡ�\n");
    return;
}

int ask_kill()
{
   object ob,me = this_player();

   command("tell "+this_player()->query("id")+" ��Ҫȥɱ�������ܣ�\n");
   message_vision(HIC "�������$N���˵�ͷ˵��������һ��֮����\n" NOR,this_player());
   ob=new("/d/heimuya/npc/obj/card4");
   ob->move(me);
   tell_object(me,"������ӻ�������һ����������������ϡ�\n");
   return 1;
}
