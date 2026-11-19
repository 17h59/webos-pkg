/* hello — premier paquet construit par webpkg-build (M3.3b) : affiche un salut et l'utilisateur courant (appel noyau getuid). */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  const char *who = argc > 1 ? argv[1] : "monde";
  printf("bonjour, %s ! (uid %d)\n", who, (int)getuid());
  return 0;
}
