// �ҹ�����    make joke by That. Nov.6.1997
#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "�����ҹ����ɣ����������µ�����Ӣ�ۡ�������˾�Ȼ����װ����ʶ���ǣ�",
        "Ϊʲ���������С�ӻ�û�����ֺ��Ǹ�С��Ů����һ���ˣ�",
        "��˭���Ը���һЩǮ��ҹè�ӵ�һǧ�����ӻ����ǵ�ʱ�����ٻ�����ɣ�",
        "���뿴������ɵ�ƨ�����ƽɳ����ʽ��",
        "�ɲ����Ը�����������Դ�㣿�´μ��������Ǹ�������ɲ�����ô���ˣ�",
        "���������ͺ¿�����ﲻ�Ƿ������������������",
        "�Ǹ�������ţ����Ϊʲô���������ǣ�",
        "���ŵ���ü��˵��Ư����",
        "���������������С�뵰����ȥ�ˣ�",
        "���������ʲô��",
        "�����ͷ�Ӻ���ǧ������һ�����⣡",
        "����Ⱥ����α���ӣ�����",
        "������ӯӯ��",
        "��..",
});

varargs void drool(string msg, string who);

void create()
{

        set_name("��Ҷ��", ({ "taoye xian", "ye" }) );
        set("title", "��ͨ����");
        set("gender", "����");
        set("age", 66);
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("env/wimpy", 100);
        set("chat_chance", 30);
        set("chat_msg", ({
		(: command("eat1") :),
		(: command("goeat") :),
		(: command("mapi1") :),
		(: command("drinkcup") :),
		(: command("ugly") :),
		(: command("mapi") :),
		(: command("slogan2") :),
		(: command("zzz") :),
		(: command("lazy") :),
		(: command("slogan") :),
		(: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "Ү", "");
        msg = replace_string(msg, "��", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
          string who;

//        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
         string who;

        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb)
        {

        case "kick":
                if( random(10)<5 ) {
                        command("say Ϊʲ�����ң���ʹҮ��");
                        break;
                }
	case "hug":
	case "kiss":
	case "mo":
	case "18mo":
	case "nocloth":
	if ( (string) ob -> query ("gender") == "����" ||
             (string) ob -> query ("gender") == "����" )
	{
		command ("chat ����ɶ��"+ ob->query("name") + "���Ҿ�ϲ�������������\n") ;
		command("chat ˭��õ���" + RANK_D->query_rude(ob)+"����Ȼ������֮�á�\n");
	}
	else
	{
		command("giggle");
		command("chat �벻��"+ ob->query("name") +"�Զ��Ѷ����������ˡ��ٿ���û���ˣ�");
	}
		message_vision("$Nҡ��ҡͷ����$n����̾���������������Ǻο���?\n",this_object(), this_player());
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "Ϊʲ��") >= 0) ) {
                if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) msg = "Ϊʲ��" + msg;
                switch(random(8)) {
                case 0: command("say " + who + "��������������"); break;
                case 1: command("say ���" + msg + " ... "); break;
                case 2: command("say �� ... "); drool(); break;
                case 3: command("say ��������� ...."); break;
                case 4: command("say " + who + "��֪���������Ĵ𰸶���������Ҫô��"); break;
                case 5: command("say " + msg + "��"); break;
                case 6: command("say " + who + "���ܲ���˵���һ�㣿"); break;
                case 7: command("say " + who + "���Ҳ������ʵ�����"); break;
                }
        }
        else if( (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "��", "��");
                switch(random(10)) {
                case 0: command("say " + who + "������˵" + msg + "��");break;
                case 1: command("say ��ȷ��" + msg + "��");     break;
                case 2: command("say " + msg + "������ʲ���ϵ��");     break;
                case 3: command("say �� ... " + who + "˵�ú�"); break;
                case 4: command("say " + who + "��Ϊʲ���" + msg + "��������Ȥ��"); break;
                case 5: command("say Ϊʲ������Ϊ" + msg + "��"); break;
                case 6: command("say ���������"); drool(); break;
                case 7: command("say �Ź�"); break;
                case 8: command("say ��һ���ɣ�"); break;
                case 9: command("say ��������� ...."); break;
                }
        }
        else if( (strsrch(msg, "��") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say ����˵" + msg + "��"); break;
                case 1: command("say ��ģ�" + msg + "��");     break;
                case 2: command("say ���" + msg + "�����ܰ���ʲ��æ��");break
;
                case 3: command("hmm"); break;
                case 4: command("say ����Ϊ" + msg + "��"); break;
                case 5: command("say ����ͬ��"); break;
                case 6: command("say ��˵�ġ�" + msg + "���Ҳ��ܹ�ͬ"); break;
                case 7: command("say �йء�" + msg + "���Ļ��⵽��Ϊֹ����");;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say Ϊʲ��˵" + msg + "?"); break;
                        case 1: command("say ��" + msg + "����ʲ����˼��"); break;
                        case 2: command("say " + msg + "��"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say ������֪��" + msg + "?"); break;
                        case 10: command("say �ո�" + who + "����˵�ˣ�" + msg);
                        case 11: command("say �ҵ�Ȼ֪����" + msg); break;
                        case 12: command("say Ȼ���أ�"); break;
                        case 13: command("say �����"); break;
                        case 14: command("say �Ҳ�������Ϊ��"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object()
{
        return 1;
}

