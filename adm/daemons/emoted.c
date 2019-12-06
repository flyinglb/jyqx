// emoted.c

#include <net/macros.h>
#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;
mapping emote;

//      The emote mapping contains the data base of emote definitions. Each emote
//      is defined in a sub-mapping with the following structure:
//
//      myself  - the message emoter will see
//      target  - the message the target will see when targeted
//      others  - the message others will see when no argument.
//
//      The emote mapping is indexed with the emote 'pattern' instead of emote
//      verb. For example, typing "smile" without argument will cause the daemon
//      search the emote mapping with "smile" as key, and typing "smile someone"
//      will cause the daemon search the emote mapping with "smile $" pattern as
//      the key, while $ means one argument.
//
//      In the message string, the following substitutions will be applied before
//      sending the messages:
//
//      $N              - name of emoter
//      $n              - name of target
//      $P              - pronoun of emoter
//      $p              - pronoun of target
//
//      Original by Annihilator@ESII (11/09/94)
//      $C              - very close call of emoter
//      $c              - close call of target
//      $R              - respect calling of target
//      $r              - rude calling of target
//      $S              - self calling of emoter
//      $s              - self-rude calling of emoter
//      aboved added by Xiang@XKX


void create()
{
        if( !restore() && !mapp(emote) )
                emote = ([]);
}

int remove()
{
        save();
        return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
// CHANNEL_D also calls this to get emote message.
varargs mixed do_emote(object me, string verb, string arg, int channel_emote,string who)
{
        string str, my_gender, target_gender, msg_postfix;
        object target;
        mapping rwho=([]); // add by ken@mud.szptt.net.cn for intermud emote at 98-1-18

        if( channel_emote && channel_emote == 4 ) {

        if( sscanf(arg,"mud=%s name=%s id=%s age=%d gender=%s respect=%s rude=%s ",
                                rwho["mud"],
                                rwho["name"],
                                rwho["id"],
                                rwho["age"],
                                rwho["gender"],
                                rwho["respect"],
                                rwho["rude"])   != 7 )

                        return "error loading intermud emote!\n";

        if( stringp(str = emote[verb]["others_target"]) ) {
//                str = replace_string(str, "$N", sprintf("%s(%s@%s)",me->name(),capitalize(me->query("id")),upper_case(Mud_name())));
                str = replace_string(str, "$N", sprintf("%s",me->name()));
                str = replace_string(str, "$C", RANK_D->query_self_close(me,rwho["age"],rwho["gender"]));
                str = replace_string(str, "$c", RANK_D->query_close(me,rwho["age"],rwho["gender"]));
                str = replace_string(str, "$R", rwho["respect"]);
                str = replace_string(str, "$r", rwho["rude"]);
                str = replace_string(str, "$p", gender_pronoun(rwho["gender"]));
//                str = replace_string(str, "$n", sprintf("%s(%s@%s)",rwho["name"],capitalize(rwho["id"]),upper_case(rwho["mud"])));
                str = replace_string(str, "$n", sprintf("%s",rwho["name"]));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        }
        return str;
        }


        if( !environment(me) ) return 0;

        if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;

        // Determine the pattern to be searched and the target.
        if ( stringp(arg) && arg != "" ) {
                target = present(arg, environment(me));

                if(!objectp(target)) {
                        // If not channel emote, only search target in our environment.
                        if(!channel_emote) return 0;
                        target = find_player(arg);
                        if( !objectp(target) ) return 0;
                }

                if( !target->is_character() || !me->visible(target) )
                        return notify_fail("��Ҫ��˭�����������\n");

                target_gender = target->query("gender");
                if( target==me ) {
                        msg_postfix = "_self";
                        target = 0;
                } else msg_postfix = "_target";
        } else msg_postfix = "";

        my_gender = me->query("gender");

        if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
                str = replace_string(str, "$N", who?who:me->name());
                str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                if( objectp(target) ) {
                        str = replace_string(str, "$C", RANK_D->query_self_close(target));
                        str = replace_string(str, "$c", RANK_D->query_close(target));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
                        str = replace_string(str, "$n", target->name());
                        str = replace_string(str, "$p", gender_pronoun(target_gender));
                }
                if( !channel_emote ) message("emote", CYN + str + NOR, me);
        }

        if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
                str = replace_string(str, "$N", who?who:me->name());
                str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$C", RANK_D->query_self_close(target));
                str = replace_string(str, "$c", RANK_D->query_close(target));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$r", RANK_D->query_rude(target));
                str = replace_string(str, "$n", target->name());
                str = replace_string(str, "$p", gender_self(target_gender));
                if( !channel_emote ) message("emote", CYN + str + NOR, target);
        }

        if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
//                str = replace_string(str, "$N", who?who:(userp(me)?sprintf("%s(%s@%s)",me->name(),capitalize(me->query("id")),upper_case(Mud_name())):me->name()));
                str = replace_string(str, "$N", who?who:(userp(me)?sprintf("%s",me->name()):me->name()));
                str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                if( objectp(target) ) {
                        str = replace_string(str, "$C", RANK_D->query_self_close(target));
                        str = replace_string(str, "$c", RANK_D->query_close(target));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
//                        str = replace_string(str, "$n", userp(target)?sprintf("%s(%s@%s)",target->name(),capitalize(target->query("id")),upper_case(Mud_name())):target->name());
                        str = replace_string(str, "$n", userp(target)?sprintf("%s",target->name()):target->name());
                        str = replace_string(str, "$p", gender_pronoun(target_gender));
                }
                if( !channel_emote ) {
                        str = CHANNEL_D->remove_addresses(str,0);
                        message("emote", CYN + str + NOR, environment(me), ({me,target}));
                }
                else return str;
        }

        // Let NPC know we are doing emote on him.
        if( objectp(target) ) target->relay_emote(me, verb);

        return 1;
}

int set_emote(string pattern, mapping def)
{
        emote[pattern] = def;
        save();
        return 1;
}

int delete_emote(string pattern)
{
        map_delete(emote, pattern);
        save();
        return 1;
}

mapping query_emote(string pattern)
{
        if( !undefinedp(emote[pattern]) ) return emote[pattern];
        else return ([]);
}

string *query_all_emote()
{
        return keys(emote);
}

mapping query_emotes()
{
        return emote;
}//debug function

