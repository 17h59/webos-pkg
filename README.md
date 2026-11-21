# webos-pkg — dépôt de paquets de webOS (PRÉ-PRODUCTION)

> **⚠ Pré-production, clés exposées.** Les clés privées qui signent ce dépôt ont été affichées dans une conversation de travail (2026-11-21). Les signatures de ce dépôt ne prouvent donc rien : il sert aux essais de webOS, pas à installer des logiciels de confiance. La production aura une nouvelle racine.

Dépôt **statique** de paquets pour [webOS](https://webos.nsi.xyz/) (`webpkg`), publié par GitHub Pages :
**`https://17h59.github.io/webos-pkg/core`** (configuré par défaut dans `/etc/webpkg/repos.json` de l'image).

> ⚠ **Pré-production.** Les clés qui signent ce dépôt sont des clés de test, sans valeur de sécurité. Elles seront remplacées au
> déploiement en production (nouvelle racine créée hors ligne).

## Contenu

```
core/repo.pub                         clé publique du dépôt « core »
core/wasm32/repo.json                 liste signée des paquets (serial croissant, date d'expiration)
core/wasm32/repo.json.sig             signature Ed25519 de repo.json
core/wasm32/repo.keycert              certificat : la clé racine certifie la clé du dépôt (90 jours)
core/wasm32/<paquet>.wpkg             paquets (tar + gzip, .PKGINFO, .FILES)
core/wasm32/<paquet>.wpkg.provenance.json   d'où vient chaque paquet (recette, sources, conteneur de construction)
core/sources/<paquet>/                recette et sources de chaque paquet (licences GPL)
```

Empreinte de la racine de pré-production : `754a59c0fa9ef29942484533d97bf2b602721445fe795c11982e5da3d18580fb`.
Empreinte de la clé du dépôt `core` : `e466cc69e9ccdb28cbe252a65766395958a89f08dbaddbc1426e934b554ae10d`.

## Héberger ailleurs

Ce ne sont que des **fichiers statiques** : n'importe quel serveur web convient (GitHub Pages, un serveur personnel, l'infrastructure
de webOS elle-même). Une seule exigence : si le dépôt n'est pas servi par la même adresse que webOS, il doit envoyer l'en-tête
`Access-Control-Allow-Origin: *` (GitHub Pages le fait). Côté webOS : `/etc/webpkg/repos.json`, champ `url`.

## Comment ces fichiers sont produits

Dans le dépôt de webOS : recettes `ports/<nom>/WEBBUILD`, construction reproductible `tools/webpkg-build.sh` (conteneur sans
réseau), dépôt signé `tools/webpkg-repo.mjs`. Les paquets se reconstruisent à l'octet près à partir de leurs sources.
