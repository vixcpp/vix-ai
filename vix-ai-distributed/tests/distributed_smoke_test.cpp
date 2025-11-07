#include <cstdlib>
#include <vix/ai/distributed/Peer.hpp>
#include <vix/ai/distributed/FederatedTrainer.hpp>
#include <vix/ai/distributed/SecureChannel.hpp>
#include <vix/ai/distributed/SyncManager.hpp>

int main()
{
    using namespace vix::ai::distributed;
    Peer p;
    if (p.id.empty())
        return EXIT_FAILURE;
    FederatedTrainer ft;
    ft.step();
    if (ft.round != 1)
        return EXIT_FAILURE;
    SecureChannel sc;
    if (!sc.handshake("ok"))
        return EXIT_FAILURE;
    SyncManager sm;
    if (sm.sync() != 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}